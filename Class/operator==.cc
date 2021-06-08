#include <iostream>
using namespace std;


class Person 
{
public:
    Person(string name,int age) : m_Name(name),m_Age(age){}
    bool operator==(Person &p)
    {
        if(m_Age == p.m_Age && m_Name == p.m_Name)
        {
            return true;
        }
        return false;
    }
    bool operator!=(Person &p)
    {
        if(m_Age == p.m_Age && m_Name == p.m_Name)
        {
            return false;
        }
        return true;
    }
    string m_Name;
    int m_Age;
};

void test01()
{
    Person p1("tom",18);
    Person p2("ton",18);

    if(p1 == p2)
    {
        cout << "p1 == p2" << endl;
    }
    cout << "p1 != p2" << endl;
}




int main()
{
    test01();
    return 0;
}
