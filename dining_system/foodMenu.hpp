#ifndef FOOD_MENU_HPP
#define FOOD_MENU_HPP

#include <iostream>
#include <string>
#include <list>

using namespace std;

//菜肴结构
//

typedef struct{
  unsigned m_foodType;
  string m_foodName;
  double m_foodPrice;
}Food;

//菜单类
//list容器里存放菜肴
//
class FoodMenu{
  protected:
    list<Food> m_foodMenu;
  public:
    //增删改查菜肴
    addIntoMenu(const Food& food);
    deleteFromMenu(const Food& food);
    getFood();
    checkAllFood();
};

class totalMenu : public FoodMenu{};

//某个餐桌的订单
//
class BoardMenu : public FoodMenu{
  private:
    double totalPrice;
    unsigned short waiterNum;
};

#endif
