#include <iostream>
using namespace std;

class Base
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Sub : public Base 
{
public:
    void func()
    {
        m_A = 10; //true  public ---> public 
        m_B = 10; //true  protected ---> protected 
        //m_C = 10; //false private ---> private 
    }
    int m_D;
};

class Son : protected Base 
{
public:
    void func()
    {
        m_A = 10; //true  public ---> protected 
        m_B = 10; //true  protected ---> protected 
        //m_C = 10; //false private ---> private 
    }
};

class Derive : private Base 
{
public:
    void func()
    {
        m_A = 10; //true  public ---> private 
        m_B = 10; //true  protected ---> private 
        //m_C = 10; //false private ---> private 
    }
};


void test01()
{
    Base B;
    //12 
    cout << "sizeof(B) = " << sizeof(B) << endl;

    Sub S1;
    //16 访问不到但是会继承下来
    cout << "sizeof(S1) = " << sizeof(S1) << endl;

}



int main()
{
    test01();

    
    return 0;
}
