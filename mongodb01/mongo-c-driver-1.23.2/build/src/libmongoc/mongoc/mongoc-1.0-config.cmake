include(CMakeFindDependencyMacro)
find_dependency(bson-1.0 1.23.2)
include("${CMAKE_CURRENT_LIST_DIR}/mongoc-targets.cmake")
