#include <iostream>
using namespace std;


class MyInteger
{
public:
    MyInteger()
    {
        m_Num = 10;
    }
    //back --
    MyInteger operator--(int)
    {
        MyInteger temp = *this;
        m_Num--;
        return temp;
    }

    MyInteger& operator--()
    {
        m_Num--;
        return *this;
    }


    int m_Num;
};


ostream& operator<<(ostream& cout , MyInteger myint)
{
    cout << myint.m_Num ;
    return cout;
}



void test01()
{
    MyInteger myint;

    cout << myint << endl;

    cout << myint-- << endl;

    cout << myint << endl;

    cout << --myint << endl;

    cout << myint << endl;

    //10 10 9 8 8 

}



int main()
{
    test01();
    return 0;
}
