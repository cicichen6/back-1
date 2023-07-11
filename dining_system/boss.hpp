#ifndef BOSS_HPP
#define BOSS_HPP

#include "person.hpp"
#include "menu.hpp"
#include "waiter.hpp"

#include <memory>
//boss
//管理主菜单
//管理waiters
//只能有一个boss

class boss : public person {
  private:
    string boss_passwd;
    static shared_ptr<boss> pboss;
    
    boss(const string& bpasswd, const string& bname, const bool& bsex)
    : person(bname, bsex)
    { boss_passwd = bpasswd; }

  public:
    friend istream& operator >> (istream&, Food&);
    friend ostream& operator << (ostream&, Food&);

    //唯一boss
    static shared_ptr<boss> getBoss(const string&, const string&, const bool&);
    //管理主菜单
    bool addIntoMainMenu();
    bool deleteFromMainMenu();

};

//全局函数
istream& operator >> (istream& input, Food& m_food){
  input >> m_food.f_name >> m_food.f_price;
  return input;
}

ostream& operator << (ostream& output, Food& m_food){
  output << m_food.f_name << m_food.f_price;
  return output;
}



shared_ptr<boss> boss::getBoss(const string& bpasswd, const string& bname, const bool& bsex){
  if(NULL == pboss){
    //pboss = make_shared<boss>(bpasswd, bname, bsex);
    auto tboss = new boss(bpasswd, bname, bsex);
    shared_ptr<boss> ttboss(tboss);
    pboss = ttboss;
  }
  return pboss;
}

bool boss::addIntoMainMenu(){
  Food a_food;
  bool ifContinue = true;
  while(ifContinue){
   cout << "输入菜名和菜价：" << endl;
   cin >> a_food;
   cout << "你输入的是：" << a_food << endl;
   mainMenu::mMenu.push_back(a_food);
   cout << "菜单中新加的是" << mainMenu::mMenu.back() << endl;
   cout << "输入是否继续（1/0)" << endl;
   cin >> ifContinue;
  }
  cout << "quit ok..." << endl;
  return true;
}

bool boss::add(){
  
}

bool boss::deleteFromMainMenu(){
 Food d_food;
 bool ifContinue
}


#endif

