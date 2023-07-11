#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
//#include "boss.hpp"
#include <vector>
//主菜单只能实例化一次
//只有boss可以操作主菜单
//
using namespace std;

typedef struct {
  string f_name;
  double f_price;
}Food;

class boss;

class mainMenu {
  private:
  //static bool initFlag;
  //只有boss可以实例化主菜单
  mainMenu();
  //主菜单是静态成员
  static vector<Food> mMenu;
  /*//增删主菜单
  addIntoMainMenu(const Food&);
  deleteFromMainMenu(const Food&);*/
  //友元类 
  friend class boss;

  public:
  //公有静态，waiter类点单时可用
  static vector<Food> getMenu() { return mMenu; }
};

//bool mainMenu::initFlag = false;
vector<Food> mainMenu::mMenu(20);

/*mainMenu::mainMenu(){
  if(!initFlag){
    cout << "初始化主菜单！" << endl;
    Food m_food;
    输入菜品
    cin >> 
  }
}*/

#endif
