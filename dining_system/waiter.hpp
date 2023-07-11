#ifndef WAITER_HPP
#define WAITER_HPP

#include "person.hpp"

class waiter : public person {
  private:
  unsigned short w_number;
  double salary;
  double achievement;
  static double all_salary;
  static unsigned short w_count;

  public:
  waiter(
      const unsigned short&,
      const double&,
      const string&,
      const bool&,
      const double& );

  ~waiter()  { w_count--; }
  
  //私有成员接口
  unsigned short getNum() const { return w_number; }
  double getSalary() const { return salary; }
  double getAchievement() const { return achievement; }

  //增桌
  //桌号，菜单，点菜单，总价
  //bool AddOneBoard()



};

#endif
