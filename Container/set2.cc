#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;


//目标 set容器保存学生信息  学生： 学号、姓名、年龄、数学、语文、外语、总分
//要求按照总分来做降序排列
class Student
{
public:
    Student(string stuid,string name,int age,double math,double ch,double en);
    
    string Stuid;
    string Name;
    int Age;
    double Math;
    double Ch;
    double En;
    double Total;
};
Student:: Student(string stuid,string name,int age,double math,double ch,double en)
  : Stuid(stuid),Name(name),Age(age),Math(math),Ch(ch),En(en)
{
  Total = math + ch + en;
}

class Comp{
public:
    bool operator()(const Student&s1,const Student&s2)
    {
        return s1.Total > s2.Total;
    }
};

void test01()
{
    Student s1("20203301","A",18,120.5,100.0,80.0);
    Student s2("20203302","B",19,110.0,99.0,70.0);
    Student s3("20203303","C",17,95.5,98.0,101.0);
    Student s4("20203304","D",20,140.0,130.0,150.0);
    Student s5("20203305","E",18,100.0,70.0,120.0);
    set<Student,Comp>Stu;
    Stu.insert(s1);
    Stu.insert(s2);
    Stu.insert(s3);
    Stu.insert(s4);
    Stu.insert(s5);
    cout << "  学号" << "   姓名" << " 年龄" << " 数学" << " 语文" << " 英语" << " 总分" << endl;
    for(auto i : Stu)
    {
        cout << i.Stuid << "  " << i.Name << "   " << i.Age << "   " << i.Math << " " << i.Ch << " " << i.En << " " << i.Total << endl;
    }


}


int main()
{
    test01();
    return 0;
}
