#include <iostream>
using namespace std;

class Web
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
};

class Java :public Web 
{
    public:

      void privat()
      {
          cout << "Java" << endl;
      }
};

class Cplusplus :public Web 
{
    public:

      void privat()
      {
          cout << "C++" << endl;
      }
};

class Python  :public Web 
{
    public:

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
    cout <<"--------------"  << endl;
    Cplusplus c;
    cout << "C++ web:" << endl;
    c.header();
    c.tailor();
    c.privat();
    cout <<"--------------"  << endl;
    Python py;
    cout << "Python web:" << endl;
    py.header();
    py.tailor();
    py.privat();

}



int main()
{   
    test01();
    return 0;
}
