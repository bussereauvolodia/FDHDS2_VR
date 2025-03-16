#pragma once
#include "ISubstanceConnector.h"
#include "SubstanceConnectorSettings.h"
#include "Engine/World.h"
#include "Containers/Ticker.h"
#include "SubstanceConnectorComponentImpl.h"


#if WITH_EDITOR
#include "ISettingsModule.h"
#endif

struct SubstanceConnectorContext {
	std::string id;
};

class FSubstanceConnectorModule : public ISubstanceConnector
{
	//Substance Core Initialization
	virtual void StartupModule() override;

	//Module cleanup
	virtual void ShutdownModule() override;

	//Module update
	virtual bool Tick(float DeltaTime);

	//Registers the Substance settings to appear within the project settings (Editor Only)
	void RegisterSettings();

	//Unregister the Substance settings from the project settings (Editor Only)
	void UnregisterSettings();


private:
	//Tick delegate to register module update
	FTSTicker::FDelegateHandle TickDelegate;


	// Inherited via ISubstanceConnector
	bool IsRunning() const override;

	Substance::Unreal::Connector::Component* comp;

	SubstanceConnectorContext* context;


};
