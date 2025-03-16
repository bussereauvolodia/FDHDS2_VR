#pragma once
#include <string>
#include <memory>

struct SubstanceConnectorContext;

namespace Substance
{
namespace Unreal
{
namespace Connector
{
//! @brief Module component, containing all the Connector application instances and
//!     managing its lifetime
class Component
{
public:
	//! @brief Constructor
	Component();

	//! @brief Destructor
	~Component();
	
	//! @brief Handle post initialization of the Substance Connector library
	//! @return True on success, false on failure
	bool postInitialization();

	//! @brief Shut down the Substance Connector instance
	//! @return True on success, false on failure
	bool shutdown();

	//! @brief Send a load sbsar message to another application
	//! @param context The context associated with the connection
	//! @param message The message containing the path to the sbsar file
	void sendLoadSbsar(unsigned int context, const std::string& message);


	//! @brief Attempt to find a context based on the application name
	//! @param application The name of the application
	//! @return Integer representing the context
	unsigned int getApplicationContext(const std::string& application);

	void setContextHandle(SubstanceConnectorContext* context);

private:
	class Impl;

	//! @brief Implementation instance
	std::unique_ptr<Impl> mImpl;
};
} // namespace Connector
} // namespace Unreal
} // namespace Substance