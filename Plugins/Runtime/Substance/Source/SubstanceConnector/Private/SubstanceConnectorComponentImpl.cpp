#include "SubstanceConnectorComponentImpl.h"
#include "SubstanceConnectorComponent.h"
#include <substance/connector/framework/export.h>
#include <substance/connector/framework/system.h>
#include <substance/connector/framework/details/connectionschema.h>
#include <substance/connector/framework/core.h>
#include <substance/connector/framework/details/callbacks.h>

#include <map>
#include <functional>
#include <string>
#include "Serialization/JsonSerializer.h"

#include "Async/Async.h"
#include "AssetToolsModule.h"
#include "SubstanceFactory.h"
#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"

namespace Substance
{
namespace Unreal
{
namespace Connector
{
//! @brief The application name of this program
static const char* const sConnectorApplicationName = "Unreal Engine";

//! @brief Map of the application name to its context
static std::map<std::string, std::pair<Substance::Connector::Framework::Details::connection_schema, int>> sApplicationList;

static SubstanceConnectorContext* sContextHandle = nullptr;

static std::vector<substance_connector_uuid_t> feature_ids;

DEFINE_LOG_CATEGORY_STATIC(LogSubstanceConnectorModule, Log, All);

void onRecvLoadSbsar(unsigned int context, const substance_connector_uuid_t* uuid, const char* message)
{
	if (sContextHandle == nullptr)
		return;

	FString messageString = message;

	TSharedPtr<FJsonObject> JsonParsed;
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(messageString);
	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
	{
        if(JsonParsed->HasField("type")) {
            if (JsonParsed->GetStringField("type") == "material") {

                FString path = JsonParsed->GetStringField("path");

                AsyncTask(ENamedThreads::GameThread, [=]() {
                    FContentBrowserModule& ContentBrowserModule = FModuleManager::Get().LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
                    FString mContentBrowserPath = FString("/Content");
                    ContentBrowserModule.Get().FocusPrimaryContentBrowser(false);
                    if(ContentBrowserModule.Get().GetCurrentPath().HasInternalPath()) {
                        mContentBrowserPath = ContentBrowserModule.Get().GetCurrentPath().GetInternalPathString();
                    } else {
                        mContentBrowserPath = ContentBrowserModule.Get().GetCurrentPath().GetVirtualPathString();
                    }

                    FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools");

                    USubstanceFactory* importFactory = NewObject<USubstanceFactory>();
                    importFactory->SuppressImportOverwriteDialog();

                    TArray<FString> SourcePaths;
                    SourcePaths.Add(path);

                    UAutomatedAssetImportData* ImportData = NewObject<UAutomatedAssetImportData>();
                    ImportData->bReplaceExisting = true;
                    ImportData->Filenames = SourcePaths;
                    
                    ImportData->DestinationPath = mContentBrowserPath;
                    ImportData->bSkipReadOnly = false;
                    ImportData->Factory = importFactory;

                    AssetToolsModule.Get().ImportAssetsAutomated(ImportData);

                    importFactory->ConditionalBeginDestroy();
                    importFactory = nullptr;
                    UE_LOG(LogSubstanceConnectorModule, Warning, TEXT("Import Sbsar: %s"), *path);
                });
		    }
        }
	}
}

void onRecvConnectionEstablished(unsigned int context, const substance_connector_uuid_t* uuid, const char* message)
{
	sApplicationList[message].second = context;

    Substance::Connector::Framework::System::connectionEstablished(context, &Substance::Connector::Framework::System::sConnectionUpdateContextId, Substance::Connector::Framework::getConnectionContext().c_str());
}

void onRecvConnectionClosed(unsigned int context, const substance_connector_uuid_t* uuid, const char* message)
{
	const auto& it = sApplicationList.find(message);
	if (it != sApplicationList.end())
	{
		sApplicationList.erase(it);
	}
}

void onRecvConnectionUpdateContext(unsigned int context, const substance_connector_uuid_t* uuid, const char* message) {
    Substance::Connector::Framework::Details::connection_schema schema;
    schema.Deserialize(std::string(message));
    const auto& it = sApplicationList.find(schema.id_name);
    if (it != sApplicationList.end())
	{
		sApplicationList[schema.id_name].first = schema;
	}
}


Component::Impl::Impl()
	: mConnectorExport(new Substance::Connector::Framework::Export)
	, mConnectorSystem(new Substance::Connector::Framework::System)
	, mOpenContext(0u)
{
    feature_ids = mConnectorSystem->getFeatureIds();

	Substance::Connector::Framework::registerApplication(mConnectorExport.get());
	Substance::Connector::Framework::registerApplication(mConnectorSystem.get());
	//typedef void (*MessageCallback)(unsigned int, const substance_connector_uuid_t* uuid, const char*)

	mConnectorExport->mRecvLoadAsset = onRecvLoadSbsar;
	mConnectorExport->mRecvUpdateSbsar = onRecvLoadSbsar;
	mConnectorExport->preInit();

	mConnectorSystem->mRecvConnectionEstablished = onRecvConnectionEstablished;
	mConnectorSystem->mRecvConnectionClosed = onRecvConnectionClosed;
    mConnectorSystem->mRecvConnectionContext = onRecvConnectionUpdateContext;
	mConnectorSystem->preInit();

	Substance::Connector::Framework::init(sConnectorApplicationName);
}

Component::Impl::~Impl()
{
}

bool Component::Impl::postInitialization()
{
	bool result = Substance::Connector::Framework::openDefaultTcp(&mOpenContext);

	if (result)
	{
		result = Substance::Connector::Framework::broadcastTcp();
	}

	return result;
}

bool Component::Impl::shutdown()
{
	bool result = false;

	result = Substance::Connector::Framework::shutdown();

	return result;
}

void Component::Impl::sendLoadSbsar(unsigned int context, const std::string& message)
{
	mConnectorExport->writeLoadSbsar(context, message.c_str());
}

unsigned int Component::Impl::getApplicationContext(const std::string& application)
{
	unsigned int context = 0u;

	if (sApplicationList.find(application) != sApplicationList.end())
	{
		context = sApplicationList[application].second;
	}

	return context;
}

void Component::Impl::onApplicationQuit()
{
	sContextHandle = nullptr;
	shutdown();
}

void Component::Impl::setContextHandle(SubstanceConnectorContext* context)
{
	sContextHandle = context;
}

} // namespace Connector
} // namespace Photoshop
} // namespace Alg
