#pragma once

#include "SubstanceConnectorComponent.h"
#include <memory>
#include <string>
#include <substance/connector/types.h>
#include "Containers/UnrealString.h"

struct SubstanceConnectorContext;

namespace Substance
{
namespace Connector
{
namespace Framework
{
class Export;
class System;
} // namespace Connector
}
namespace Unreal
{
namespace Connector
{
//! @brief Implementation of the component class, containing the API instances
class Component::Impl
{
public:
	//! @brief Default constructor
	Impl();

	//! @brief Destructor
	~Impl();

	//! @brief Method to finalize Connector setup after object construction
	//! @return True on success, false on failure
	bool postInitialization();

	//! @brief Method to finalize Connector shutdown prior to unloading the module
	//! @return True on success, false on failure
	bool shutdown();

	//! @brief Send a load sbsar message to another application
	//! @param context The context associated with the connection
	//! @param message The message containing the path to the sbsar file
	void sendLoadSbsar(unsigned int context, const std::string& message);

	//void onRecvLoadSbsar(unsigned int context, const substance_connector_uuid_t* uuid, const char* message);
	//! @brief Attempt to find a context based on the application name
	//! @param application The name of the application
	//! @return Integer representing the context
	unsigned int getApplicationContext(const std::string& application);

	//! @brief Slot used to connect to application exit to handle cleanup
	void onApplicationQuit();

	void setContextHandle(SubstanceConnectorContext* context);

private:
	//! @brief Application instance for handling importing sbsar files
	std::unique_ptr<Substance::Connector::Framework::Export> mConnectorExport;

	//! @brief Application instance for handling system events, such as on
	//!     establish and closing of a connection
	std::unique_ptr<Substance::Connector::Framework::System> mConnectorSystem;

	//! @brief The open context for this application, used for others to
	//!     connect to when they establish the connection
	unsigned int mOpenContext;
};
} // namespace Connector
} // namespace Unreal
} // namespace Substance