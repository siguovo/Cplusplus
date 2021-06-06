#include <iostream>
using namespace std;
#include <string>

void func()
{
    cout << "func()" << endl;
}
void func(int a)
{
    cout << "func(int a)"<< endl;
}
void func(string a)
{
    cout << "func(string a)" << endl;
}

void func(int a ,string b)
{
    cout << "func(int a , string b)" << endl;
}
void func(string a , int b)
{
    cout << "func(string a, int b)" << endl;
}
//ps:不能用返回值不同来实现函数重载
//int func(int a);// 是错误的

//1.参数不同可以
//2.参数个数不同可以
//3.参数类型不同可以
//4.前提条件在同一个作用域下
//5.不能仅仅依靠返回值不同来重载函数
int main()
{
  
    func();
    func(10);
    func("aaa");
    func(10,"aaa");
    func("aaa",10);


    return 0;
}
/*
 * 引用加const也可以作为函数重载的条件
void func(int &a)
{
    cout << "func(int& a)"<<endl;
}
void func(const int&a)
{
    cout << "func(const int& a)" << endl;
}

//函数的默认参数会导致函数调用出现二义性，不能重载
void func2(int a ,int b = 10)
{
    cout << "func2(int a, int b = 10)" << endl;
}

void func2(int a)
{
    cout << "func2(int a)" << endl;
}
*/
