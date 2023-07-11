cmake_minimum_required(VERSION 3.1)

set(project_name example-mongodb)

project(${project_name})

set(CMAKE_CXX_STANDARD 11)

add_library(${project_name}-lib
        ./db.cpp
        ./db.hpp
        ./appComponent.hpp
        ./SwaggerComponent.hpp
        ./UserController.hpp
)

find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)
find_package(oatpp          1.3.0 REQUIRED)
find_package(oatpp-swagger  1.3.0 REQUIRED)
find_package(oatpp-mongo    1.3.0 REQUIRED)

include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")
link_directories(
    /usr/local/lib/mongocxx/v_noabi
    /usr/local/lib/bsoncxx/v_noabi
)

if (TARGET mongo::mongocxx_shared)
    target_link_libraries(${project_name}-lib
            PUBLIC mongo::mongocxx_shared
    )
    message("mongo::mongocxx_shared is used")
elseif(TARGET mongo::mongocxx_static)
    target_link_libraries(${project_name}-lib
            PUBLIC mongo::mongocxx_static
    )
endif()


target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-swagger
        PUBLIC oatpp::oatpp-mongo
)

add_definitions(
        -DOATPP_SWAGGER_RES_PATH="${oatpp-swagger_INCLUDE_DIRS}/../bin/oatpp-swagger/res"
)

add_executable(${project_name}
            ./app.cpp)

target_link_libraries(${project_name} ${project_name}-lib)
add_dependencies(${project_name} ${project_name}-lib)

