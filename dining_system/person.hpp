#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

using namespace std;

class person {
  private:  
  string name;
  bool sex;

  protected:
  person(const string&, const bool&);

  public:
  string getName() const { return name; }
  bool getSex() const { return sex; }
  
  void setNameSex(const string&, const bool&);

};

person::person(const string& s_name, const bool& s_sex) : 
  name(s_name), sex(s_sex) {}

void person::setNameSex(const string& m_name, const bool& m_sex){
  name = m_name;
  sex = m_sex;
}

#endif

