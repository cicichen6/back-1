#ifndef   STUDAO_HPP
#define   STUDAO_HPP

#include "daoBase.hpp"
#include "../models/stuModel.hpp"


class stuDao : public cyz_oopcpp_dao::daoBase {
  private:
    shared_ptr<Connection> conn;
    void effectRows(shared_ptr<Statement> stmt);
  public:
    stuDao();
    void addStudent(students& student);
    void deleteStudent(int idToRm);
    void deleteAll();
    void queryAll();
};

stuDao::stuDao(){
  conn = daoBase::getConnection();
  conn->setSchema("test");
}

void stuDao::effectRows(shared_ptr<Statement> stmt){
  int rows = stmt->getUpdateCount();
  cout << rows << "行受影响！" << endl;
}

void stuDao::addStudent(students& student){
  const string sql = "INSERT INTO test(idStudent, name) VALUES(?, ?)";
  shared_ptr<PreparedStatement> pstmt(conn->prepareStatement(sql));
  pstmt->setInt(1, student.studentId);
  pstmt->setString(2, student.name);
  int ret = pstmt->executeUpdate();
  if(ret == 1){
    cout << "insert successfully." << endl;
  }
  daoBase::getCounts();
}

void stuDao::deleteStudent(int idToRm){
  const string sql =  "DELETE  FROM test WHERE id = " + to_string(idToRm);
  shared_ptr<Statement> stmt(conn->createStatement());
  stmt->execute(sql);
  effectRows(stmt);
}

void stuDao::deleteAll(){
  const string sql = "DELETE FROM test";
  shared_ptr<Statement> stmt(conn->createStatement());
  stmt->execute(sql);
  effectRows(stmt);
}

 void stuDao::queryAll(){
    const string sql = "SELECT * FROM test";
    shared_ptr<Statement> stmt(conn->createStatement());
    shared_ptr<ResultSet> res(stmt->executeQuery(sql));
    while(res != NULL && res->next()){
      students student;
      list
      int id = res->getInt("idStudent");
      cout << id << endl;
    }              
}          
  



#endif


