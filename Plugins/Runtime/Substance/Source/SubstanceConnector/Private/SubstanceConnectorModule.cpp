#include "SubstanceConnectorModule.h"
#include "SubstanceConnectorPrivatePCH.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "Modules/ModuleManager.h"

#include "Misc/MessageDialog.h"
#if WITH_EDITOR
#include "Editor.h"
#endif

#define LOCTEXT_NAMESPACE "SubstanceConnectorModule"

DEFINE_LOG_CATEGORY_STATIC(LogSubstanceConnectorModule, Log, All);

void FSubstanceConnectorModule::StartupModule()
{
	context = new SubstanceConnectorContext();
	if (!IsRunningDedicatedServer())
	{
		RegisterSettings();

		TickDelegate = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateRaw(this, &FSubstanceConnectorModule::Tick));

		comp = new Substance::Unreal::Connector::Component();
		comp->postInitialization();
		comp->setContextHandle(this->context);
	}
}

void FSubstanceConnectorModule::ShutdownModule()
{
	FTSTicker::GetCoreTicker().RemoveTicker(TickDelegate);
	UnregisterSettings();
	comp->shutdown();
}

bool FSubstanceConnectorModule::Tick(float DeltaTime)
{
	return false;
}

void FSubstanceConnectorModule::RegisterSettings()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Substance Connector",
			LOCTEXT("SubstanceConnectorSettingsName", "Substance Connector"),
			LOCTEXT("SubstanceConnectorSettingsDescription", "Configure the Substance Connector plugin"),
			GetMutableDefault<USubstanceConnectorSettings>()
		);
	}
#endif
}

void FSubstanceConnectorModule::UnregisterSettings()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "Substance Connector");
	}
#endif
}

bool FSubstanceConnectorModule::IsRunning() const
{
	return false;
}

IMPLEMENT_MODULE(FSubstanceConnectorModule, SubstanceConnector);

#undef LOCTEXT_NAMESPACE

