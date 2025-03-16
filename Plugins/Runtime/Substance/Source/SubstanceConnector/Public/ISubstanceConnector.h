#pragma once
#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

/** The public interface of the SubstanceConnector module */
class ISubstanceConnector : public IModuleInterface
{
public:
	virtual bool IsRunning() const = 0;
};
