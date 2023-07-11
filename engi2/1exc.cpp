//矩形生成时增加个数，并累计总面积，消亡时减少个数，减少其面积。随时可以查看其存在的个数和总面积。
//
//一个班级，由老师，学生，课程组成。给所有学生成绩排名，老师加分会给学生成绩加分。


#include <iostream>
#include <string.h>
#include <memory>

using namespace std;

class rectangle {

private:
  int w, h;
  char* recName;
  static int totalNum;
  static int totalArea;
public:
  rectangle(int _w, int _h, const  char* _recName);
  rectangle(const rectangle& _rec);
  ~rectangle();
  rectangle func(rectangle);
  static void checkRecs();
};

int rectangle::totalNum = 0;
int rectangle::totalArea = 0;

rectangle::rectangle(int _w, int _h, const char* _recName){
  recName = NULL;
  if(_recName != NULL) {
    recName = new char [strlen(_recName) + 1];
    strcpy(recName, _recName);
    cout << "manual constructor." << endl;
  }
  //*recName = _recName;
  w = _w;
  h = _h;
  totalNum++;
  totalArea += w*h;
}

//深复制，复制构造函数
rectangle::rectangle(const rectangle& _rec){
  recName = NULL;
  if(_rec.recName != NULL) {
    recName = new char [strlen(_rec.recName) + 1];
    strcpy(recName, _rec.recName);
    cout << "copy constructor." << endl;
  }
  w = _rec.w;
  h = _rec.h;
  totalNum++;
  totalArea += w*h;
}

rectangle::~rectangle(){
  delete [] recName;
  totalNum--;
  totalArea -=w*h;
}
void rectangle::checkRecs(){
  cout << "totalNum is " << totalNum << endl;
  cout << "totalArea is" << totalArea << endl;
}

rectangle rectangle::func(rectangle _rec){
  cout << "func : " << _rec.w << _rec.h << endl;
  rectangle funcRec(_rec);
  return funcRec;
}

int main(){
  rectangle a(2, 3, "a_rec");
  rectangle::checkRecs();
  rectangle b = a;
  rectangle::checkRecs();
  rectangle c(b);
  rectangle::checkRecs();
  c.func(b);
  rectangle::checkRecs();
  return 0;
}
