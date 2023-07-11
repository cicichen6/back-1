#ifndef usercontroller_hpp
#define usercontroller_hpp
#include <iostream>
#include "db.hpp"
#include "oatpp/encoding/Url.hpp"

#include "oatpp-swagger/Types.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include <bsoncxx/builder/basic/array.hpp>
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/data/stream/BufferStream.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"
#include <bsoncxx/builder/basic/document.hpp>
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

using bsoncxx::builder::basic::make_array;

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
    ENDPOINT_INFO(createLocation) {
      info->summary = "Create new location";
      info->addResponse<oatpp::String>(Status::CODE_200, "application/json");
      info->addConsumes<oatpp::List<Int32>>("application/json");
    }
    ENDPOINT("POST", "/addLoc", createLocation,
      HEADER(oatpp::List<Int32>,c),QUERY(String, name), QUERY(String, loc_type), QUERY(Int32, a), QUERY(Int32, b) ) {
      auto doc_param = make_document(
           kvp("type", loc_type),
           kvp("coordinates",make_array(a,b) )
            );  
      auto doc_value = make_document(
            kvp("name", name),
            kvp("location", doc_param)
            );
      return createResponse(Status::CODE_200, m_database->createLocation(doc_value));
    }

     ENDPOINT_INFO(A) {
      info->summary = "Create new location";
      info->addResponse<oatpp::String>(Status::CODE_200, "application/json");
    info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
     }

    ENDPOINT("POST","/AA",A,
       BODY_STRING(String, body)) {
       body.saveToFile("my_file.png"); 
      return createResponse(Status::CODE_200, "ok");
    }
    

};

#include OATPP_CODEGEN_END(ApiController)

#endif

