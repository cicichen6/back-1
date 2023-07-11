cmake_minimum_required(VERSION 3.10)

set(project_name test03)
project(${project_name})
set(CMAKE_CXX_STANDARD 11)

find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)
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


add_executable(urtarget ./test03.cpp)
target_link_libraries(urtarget mongo::mongocxx_shared)
