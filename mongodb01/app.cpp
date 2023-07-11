#include "./UserController.hpp"
#include "./appComponent.hpp"
#include "oatpp-swagger/Controller.hpp"
#include "oatpp/network/Server.hpp"

#include <mongocxx/instance.hpp>
#include <iostream>

void run(const oatpp::base::CommandLineArguments& args) {
  mongocxx::instance instance{};

  appComponent components(args);
  auto router = components.httpRouter.getObject();

  oatpp::web::server::api::Endpoints docEndpoints;

  docEndpoints.append(router->addController(UserController::createShared())->getEndpoints());
  router->addController(oatpp::swagger::Controller::createShared(docEndpoints));

  oatpp::network::Server server(components.serverConnectionProvider.getObject(),
                                components.serverConnectionHandler.getObject());
  OATPP_LOGD("Server", "Running on port %s...", components.serverConnectionProvider.getObject()->getProperty("port").toString()->c_str());

  server.run();

}

int main(int argc, const char * argv[]) {

  oatpp::base::Environment::init();

  run(oatpp::base::CommandLineArguments(argc, argv));
  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << "\n";
  std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << "\n\n";

  oatpp::base::Environment::destroy();

  return 0;
}
