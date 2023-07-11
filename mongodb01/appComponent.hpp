#ifndef appComponent_hpp
#define appComponent_hpp

#include "db.hpp"
#include "SwaggerComponent.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/server/HttpRouter.hpp"

#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

#include "oatpp/core/base/CommandLineArguments.hpp"
#include "oatpp/core/macro/component.hpp"

#include <mongocxx/client.hpp>

class appComponent {
  private:
    oatpp::base::CommandLineArguments m_cmdArgs;
  public:
    appComponent(const oatpp::base::CommandLineArguments& cmdArgs)
      : m_cmdArgs(cmdArgs)
    {}
  public:
    SwaggerComponent swaggerComponent;
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, serverConnectionProvider)([] {
    return oatpp::network::tcp::server::ConnectionProvider::createShared({"192.168.91.131", 8000, oatpp::network::Address::IP_4});
  }());
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)([] {
    return oatpp::web::server::HttpRouter::createShared();
  }());
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, serverConnectionHandler)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router); 
    return oatpp::web::server::HttpConnectionHandler::createShared(router);
  }());

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, apiObjectMapper)([] {
    auto objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
    objectMapper->getDeserializer()->getConfig()->allowUnknownFields = false;
    objectMapper->getSerializer()->getConfig()->useBeautifier = true;
    return objectMapper;
  }());

    OATPP_CREATE_COMPONENT(std::shared_ptr<db::Database>, database)([this] {

    oatpp::String connectionString = std::getenv("DEMO_MONGO_CONN_STR");
    if(!connectionString){
      connectionString = m_cmdArgs.getNamedArgumentValue("--conn-str", "mongodb://localhost/UserDB");
    }

    mongocxx::uri uri(*connectionString);
    return std::make_shared<db::Database>(uri, "UserDB", "all");

  }());
};

#endif
