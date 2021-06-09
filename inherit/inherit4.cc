#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base gouzao" << endl;
    }
    ~Base()
    {
        cout << "Base xigou" << endl;
    }
};

class Son : public Base 
{
public:
    Son()
    {
        cout << "Son gouzao" << endl;
    }
    ~Son()
    {
        cout << "Son xigou" << endl;
    } 
};

void test01()
{
    //Bg --> Sg --> Sx -->Bx
    Son s1;
}

class Base2
{
public:
    Base2()
    {
        m_A = 10;
    }
    int m_A;
};

class Son2 : public Base2 
{
public:
    Son2()
    {
        m_A = 20;
    }
    int m_A;
};

void test02()
{
    Son2 s;
    cout << "s.m_A = " << s.m_A << endl;

    //zuoyongyu
    cout << "B.s.m_A = " << s.Base2::m_A << endl; 

}

//static 
class Base3
{
public:
    static int m_A;
};
int Base3::m_A = 10;

class Son3 : public Base3 
{
public:
    static int m_A;
};
int Son3::m_A = 20;

void test03()
{
    Son3 s;
    cout << "object -----------" << endl;
    cout << "s.m_A = " << s.m_A << endl;
    cout << "B.s.m_A = " << s.Base3::m_A << endl;
    cout << "Class ------------" << endl;
    cout << "Son3 m_A = " << Son3::m_A << endl;
    cout << "Base3 m_A = " << Son3::Base3::m_A << endl;
}



int main()
{
    //test01();
    //test02();
    test03();

    return 0;
}
