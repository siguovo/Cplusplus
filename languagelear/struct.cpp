#include <iostream>
using namespace std;

class Person
{
  public:
    Person()
    {
      cout << "moren" << endl;
    }
    Person(int age)
    {
      m_Age = age;
      cout << "youcan" << endl;
    }
    Person(const Person& p)
    {
      m_Age = p.m_Age;
      cout << "copy" << endl;
    }

  int m_Age;
};

void test01()
{
    //括号法调用
    Person p1; //这里不能加() ,会被当成一个普通函数的声明
    Person p2(10);
    Person p3(p1);
    
    cout << endl;
    //显示法
    Person p4;
    Person p5 = Person(20); //Person(20) 是一个匿名对象,执行完这一行就会被释放
    Person p6 = Person(p5);

    cout << endl;
    //隐式转换法
    Person p7;
    Person p8 = 30; //等于 Person p8 = Person(30);
    Person p9 = p8; //等于 Person p9 = Person(p8);
}

int main()
{
    test01();

    return 0;
}
