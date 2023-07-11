#ifndef swaggercomponent_hpp
#define swaggercomponent_hpp

#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Resources.hpp"
#include "oatpp/core/macro/component.hpp"

class SwaggerComponent {
  public:
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::DocumentInfo>, swaggerDocumentInfo) ([] {
      oatpp::swagger::DocumentInfo::Builder builder;

      builder
      .setTitle("Oat++ MongoDB raw")
      .setVersion("1.0")
      .setContactName("self")
      .setContactUrl("https://oatpp.io/")

      .addServer("http://192.168.91.131:8000", "server on  192.168.91.131");

      return builder.build();

        } () );

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Resources>, swaggerResources) ([] {
      return oatpp::swagger::Resources::loadResources(OATPP_SWAGGER_RES_PATH);
    } () );

};

#endif
