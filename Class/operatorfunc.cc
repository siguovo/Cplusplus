#include <iostream>
#include <string>
using namespace std;


class Myprint
{
  public:
    //Copy function 
    void operator()(string text)
    {
        cout << text << endl;
    }

};
void Myprint2(string text)
{
    cout << text << endl;
}

class MyAdd
{
  public:
    int operator()(int num1,int num2)
    {
        return num1 + num2;
    }


};

void test01()
{
    Myprint My;
    My("hello world!");

    Myprint2("hello world2");

    MyAdd myadd;
    int ret = myadd(10,10);
    cout << ret << endl;
    //匿名函数对象
    cout << MyAdd()(10,20) << endl;
}




int main()
{
    test01();
    return 0;
}
