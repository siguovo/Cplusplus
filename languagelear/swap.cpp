#include<iostream>
using namespace std;


void Myswap01(int a , int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "Myswap01 a = " << a << " b = "<< b << endl;
}
void Myswap02(int *a ,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "Myswap02 a = " << *a << " b = "<< *b << endl;

}

void Myswap03(int&a ,int&b) //引用的方式传参
{
    int temp = a;
    a = b;
    b = temp;
    cout << "Myswap03 a = " << a << " b = "<< b << endl;

}
void test01();

int main()
{
    int a = 10;
    int b = 20;
    Myswap01(a,b);
    cout << "a = " << a << " b = " << b << endl;
    Myswap02(&a,&b);
    cout << "a = " << a << " b = " << b << endl;
    Myswap03(a,b);
    cout << "a = " << a << " b = " << b << endl;
    test01();


    return 0;

}



//引用的实质
void test01()
{
    int a = 10;

    int& ref = a;

    int* const res = &a; //const 修饰的变量 不可更改

    cout << "ref = "<< ref << endl;
    cout << "res = "<< *res << endl;
}
