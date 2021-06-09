#include <iostream>
using namespace std;

//Java web
class Java
{
  public:
    void header()
    {
        cout << "public header" << endl;
    }
    void tailor()
    {
        cout << "public header" << endl;
    }
    void privat()
    {
        cout << "Java" << endl;
    }
};

//C++ web
class Cplusplus
{
  public:
    void header()
    {
        cout << "public header" << endl;
    }
    void tailor()
    {
        cout << "public header" << endl;
    }
    void privat()
    {
        cout << "C++" << endl;
    }
};
//Python
class Python
{
  public:
    void header()
    {
        cout << "public header" << endl;
    }
    void tailer()
    {
        cout << "public header" << endl;
    }
    void privat()
    {
        cout << "Python" << endl;
    }

};

void test01()
{
    Java java;
    cout << "java web:" << endl;
    java.header();
    java.tailor();
    java.privat();

    Cplusplus c;
    cout << "C++ web" << endl;
    c.header();
    c.tailor();
    c.privat();

    Python py;
    cout << "Python web" << endl;
    py.header();
    py.tailer();
    py.privat();

}



int main()
{   
    test01();
    return 0;
}
