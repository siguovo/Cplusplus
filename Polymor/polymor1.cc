#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base Gouzao" << endl;
    }
    virtual void Show()
    {
        cout << " Base show" << endl;
    }

    //普通父类析构
    //~Base(){}
    //虚析构
    virtual ~Base()
    {
        cout << "Base xigou " << endl;
    }
    //纯虚析构 ps-->纯虚析构一定要有具体实现，因为可能父类自己也有堆区的成员
    //virtual ~Base() = 0;
};
//Base::~Base(){}

class Son : public Base 
{
public:
    Son(string name)
    {
        m_Name = new string(name);
        cout << "Son gouzao" << endl;
    }

    void Show()
    {
        cout << "Son show" << endl;
    }

    ~Son()
    {
        if(m_Name != NULL)
        {
            delete m_Name;
            m_Name = NULL;
            cout << "Son xigou" << endl;
        }
    }
    string* m_Name;
};

void test01()
{
    //父类中没有纯虚函数或者纯虚析构的时候可以初始化对象
    //父类中存在纯虚函数或者纯虚析构的时候不能用父类初始化对象（此时父类是抽象类）
    //父类中的纯虚函数可以只声明，不用实现
    //父类中的纯虚析构要有声明并且要有具体实现，否则报错
    //父类中有纯虚函数的时候，子类继承的时候必须要重写父类中的纯虚函数
    //不重写父类的纯虚函数那么这个类也是抽象类，不能实例化对象
    //一般当子类中有开辟在堆区的成员时，父类才会使用虚析构或者纯虚析构
    //Base d;
    Base* d = new Son("tom");
    d->Show();
    delete d;

}


int main()
{
    test01();
    return 0;
}
