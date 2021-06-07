#include <iostream>
using namespace std;
#include<string>


class Person1
{

};

class Person2
{
  public:
    int m_A;
};

class Person3
{
  public:
    int A;
    static int B;
    void func(){}
    static void func2(){}
};


void test01()
{
  Person1 p;

  //空对象所占空间大小为1字节
  cout << sizeof(p) << endl;
  
  //非空对象占空间为对象的大小4字节
  Person2 p2;
  cout << sizeof(p2) << endl;

  //静态成员变量不属于类的对象上，不记录在类的内存中，大小为4字节
  //非静态成员函数和静态成员函数都不属于类的对象上
  Person3 p3;
  cout << sizeof(p3) << endl;
}


int main()
{
  test01();

  return 0;
}
