#ifndef usercontroller_hpp
#define usercontroller_hpp

#include "db.hpp"

#include "oatpp-swagger/Types.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/data/stream/BufferStream.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"
#include <bsoncxx/builder/basic/document.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

#include OATPP_CODEGEN_BEGIN(ApiController)

class UserController : public oatpp::web::server::api::ApiController {
  private:
    OATPP_COMPONENT(std::shared_ptr<db::Database>, m_database);

  public:
    UserController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) /* Inject object mapper */)
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
    static std::shared_ptr<UserController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)){
        return std::make_shared<UserController>(objectMapper);
    }
  public:
    ENDPOINT_INFO(createUser) {
      info->summary = "Create new User";
      info->addResponse<oatpp::String>(Status::CODE_200, "application/json");
    }
    ENDPOINT("POST", "/addUsers", createUser,
        QUERY(String, m_name),QUERY(Int32, m_age)) {
        auto doc_value = make_document(
            kvp("name", m_name),
            kvp("age", m_age)
            );
      return createResponse(Status::CODE_200, m_database->createUser(doc_value));
    }
};

#include OATPP_CODEGEN_END(ApiController)

#endif

