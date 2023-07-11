#ifndef db_hpp
#define db_hpp

#include <mongocxx/pool.hpp>
#include <bsoncxx/document/value.hpp>
#include "oatpp/core/Types.hpp"

namespace db {
  class Database {
  private:
    std::shared_ptr<mongocxx::pool> m_pool;
    std::string m_databaseName;
    std::string m_collectionName;
  public:
    Database(const mongocxx::uri &uri, const std::string &dbName, const std::string &collectionName);

    oatpp::String createUser(bsoncxx::document::value doc);
  };
}

#endif
