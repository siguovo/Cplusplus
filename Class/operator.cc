#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//运算符重载是c++11 的新特性 编译的时候加上
//g++ -std=c++11 operatot.cpp -o operator 
class Person 
{
  public:
    //成员函数重载+ 
    /*
    Person operator+(Person &p)
    {
      Person temp;
      temp.m_A = this->m_A + p.m_A;
      temp.m_B = this->m_B + p.m_B;

      return temp;
    }*/
    //不可以使用成员函数重载<<运算符
    //void operator<<()
    int m_A;
    int m_B;
};

//全局作用域下重载+ 运算符
Person operator+(Person &p1,Person &p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;

    return temp;
}
//链式编程思想，无线追加
ostream& operator<<(ostream &cout ,Person &p)
{
    cout << p.m_A << " " << p.m_B ; 
    return cout;
}





void test01()
{

  Person p1;
  p1.m_A = 10;
  p1.m_B = 10;
  Person p2;
  p2.m_A = 20;
  p2.m_B = 20;

  Person p3 = p1 + p2;
  //成员函数的本质是:
  //Person p3 = p1.operator+(p2);
  //全局函数的本质是:
  //Person p3 = operator+(p1,p2);
  
 // cout << p3.m_A << endl;
 // cout << p3.m_B << endl;

  //重载<< 运算符
  cout << p3 << endl;

}

int main()
{

  test01();


  return 0;
}
