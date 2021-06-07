#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
  
  static void func() //静态成员函数只能访问静态成员，不能访问非静态成员
  {
    m_A = 10;
    cout << "static function " << endl;
  }


  static int m_A;
  int m_B;
};

int Person::m_A = 0;

void test01()
{
  Person p;
  p.func();//通过类的对象访问静态成员函数

  Person::func();//直接通过类的作用域来访问静态成员函数
}

int main()
{
    test01();
    return 0;
}
