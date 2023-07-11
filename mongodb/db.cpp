#include "db.hpp"
#include "oatpp/core/data/stream/BufferStream.hpp"
#include <cassert>
#include <mongocxx/client.hpp>
#include <mongocxx/options/insert.hpp>
#include <mongocxx/exception/operation_exception.hpp>
//#include <mongocxx/collection>
#include <bsoncxx/builder/stream/document.hpp>

namespace db {
  Database::Database(const mongocxx::uri &uri, const std::string &dbName, const std::string &collectionName)
    : m_pool(std::make_shared<mongocxx::pool>(uri)), m_databaseName(dbName), m_collectionName(collectionName)
  {}

  oatpp::String Database::createLocation(bsoncxx::document::value doc) {
    auto conn = m_pool->acquire();
    auto collection = (*conn)[m_databaseName][m_collectionName];
    auto doc_view = doc.view();
    auto insert_one_result = collection.insert_one(doc_view);
    assert(insert_one_result);
    oatpp::String res = "yesyes";
    return res;
  }
}
