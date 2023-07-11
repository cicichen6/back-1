#include <cstdint>
#include <iostream>
#include <vector>

#include <bsoncxx/builder/basic/document.cpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;


int main () {
  mongocxx::instance instance{};
  mongocxx::uri uri("mongodb://localhost:27017");
  mongocxx::client client(uri);
}
