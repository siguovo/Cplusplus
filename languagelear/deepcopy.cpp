#include<iostream>
using namespace std;
#include<string>

class Person{
public:
    Person(string name,int age)
    {
      cout << "gouzao function"<< endl;
      this->m_Name = name;
      this->m_Age = age;
    }
    Person(const Person& p)
    {
      this->m_Name = p.m_Name;
      this->m_Age = p.m_Age;
      cout <<"copy function"<< endl;
    }
    ~Person()
    {
      cout << "xigou function" << endl;
    }
    string m_Name;
    int m_Age;
};
void test01()
{
    //Person p1("tom", 18);
    Person* p3 = new Person("jerry",19);
    cout << p3->m_Name << ' ' << p3->m_Age << endl;

    cout << "------ "<< endl;
    delete p3; 
    //Person p2 = p1;
}
class Person2{
public:
    Person2(string name,int age,int height);

    Person2(const Person2& p)
    {
        this->m_Name = p.m_Name;
        this->m_Age = p.m_Age;
        this->m_Height = new int(*p.m_Height);
        cout << "copy function" << endl;
    }

    ~Person2()
    {
        if(this->m_Height != NULL)
        {
            delete this->m_Height;
            this->m_Height = NULL;
        }
        cout << "xigou function" << endl;
    }

    string m_Name;
    int m_Age;
    int* m_Height;
};
Person2::Person2(string name,int age,int height) : 
  m_Name(name),m_Age(age){
      m_Height = new int (height);
      cout << "gouzao function" << endl;
  }

void test02()
{
    Person2 p2("tom",11,160);

    Person2 p3(p2);

}


int main()
{
    //test01();
    test02();
    return 0;
}



/*
class Myson
{
  public:
    Myson(int age ,int height)
    {
      m_Age = age;
      m_Height = height;
    }
    Myson(const Myson& s)
    {
      m_Age = s.m_Age;
      m_Height = new int(*s.m_Height);
    }
    ~Myson()
    {
      if(m_Height != NULL)
      {
        delete m_Height;
        m_Height = NULL;
      }
    }

    int m_Age;
    int* m_Height;
};
*/










