#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <ostream>
using namespace std;


class MyInteger
{
  friend ostream& operator<<(ostream& cout ,MyInteger Myint);
  public:
    MyInteger()
    {
      m_Num = 0;
    }
    //前置++ 返回引用是为了一直对一个数据操作
    MyInteger& operator++()
    {
        //先自增
        m_Num++;
        //返回自身
        return *this;
    }
    //后置++ 不能返回引用
    MyInteger operator++(int)
    {
      //保存当下值
      MyInteger temp = *this;
      //再进行++
      m_Num++;
      //返回保存的值即可
      return temp;
    }
    
  private:
    int m_Num;
};

ostream& operator<<(ostream &cout ,MyInteger Myint)
{
    cout << Myint.m_Num; 
    return cout;
}

void test01()
{
    MyInteger Myint;

    cout << Myint << endl;
    cout << ++Myint << endl;
}
void test02()
{
    MyInteger myint;

    cout << myint++ << endl;
    cout << myint << endl;

}

int main()
{
  test01();
  test02();

  return 0;

}
