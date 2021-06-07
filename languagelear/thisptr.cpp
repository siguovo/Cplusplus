#include <iostream>
using namespace std;

class Person
{
  public:
    Person(int a,int b)
    {
      this->a = a;
      this->b = b;
    }
    //返回this指针一定要使用引用(&)的方式返回
    //链式编程思想
    //引用的方式返回不会创建新的对象，还是这一个
    //不加引用就相当于拷贝构造了，创建一个新的对象
    Person& PersonAdd(Person& p)
    {
      this->a += p.a;
      return *this;
    }
    int a;
    int b;

};
void test01()
{
  Person p1(11,22);

  cout << "a = " << p1.a << " b = "<< p1.b << endl;

}
void test02()
{
  Person p1(10,10);
  Person p2(20,20);

  //p2.PersonAdd(p1);
  p2.PersonAdd(p1).PersonAdd(p1);
  cout << "a = " << p2.a << endl;

}
int main()
{

  //test01();
  test02();
  return 0;
}
