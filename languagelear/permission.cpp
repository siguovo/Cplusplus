#include <iostream>
using namespace std;
#include <string>
class Person
{
  public:
    string m_Name;

  protected:
    string m_Car;

  private:
    string m_Passwd;

  public:
    void func()
    {
        m_Name = "Tom";
        m_Car = "BMW";
        m_Passwd = "123456";
    }
};



void test01()
{
    Person p;
    p.m_Name = "jerry";
    //p.m_Passwd = "111"; //private
    //p.m_Car = "wuling"; //protected
}
/*class 默认权限是private
 *struct 默认权限是public
*/

class Person2
{
  public:
    void setName(string name) //提供写权限
    {
      m_Name = name;
    }
    string getName() // 提供访问接口
    {
      return m_Name;
    }
    void setAge(int age) //自己设置
    {
        if(age < 0 || age > 150)
        {
            age = 0;
            cout << "error" <<endl;
        }
        m_Age = age;
    }
    int getAge() //私有属性，只提供访问
    {
      m_Age = 0;
      return m_Age;
    }
  private:
    string m_Name;
    int m_Age;
};

void test02()
{
    Person2 p;
    p.setAge(10);
    p.setName("李四");
    cout << p.getAge() << ' ' << p.getName() << endl;
}



int main()
{
    test02();
    //test01();
    return 0;
}
