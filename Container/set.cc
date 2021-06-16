#include<iostream>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;

class Cmp 
{
public:
  bool operator()(int a , int b){
      return a > b;
  }

};
void test01()
{ 
    set<int>s1;
    //会自动排好序 而且没有重复元素
    s1.insert(2);
    s1.insert(1);
    s1.insert(3);
    s1.insert(3);
    cout << "升序 ---> :";
    for_each(s1.begin(),s1.end(),[](const int a) { cout << a << " ";});
    cout << endl;
    //排降序要利用仿函数 
    set<int,Cmp>s3;
    s3.insert(1);
    s3.insert(1);
    s3.insert(3);
    s3.insert(2);
    cout << "<---降序 :";
    for_each(s3.begin(),s3.end(),[](const int a) { cout << a << " ";});
    cout << endl;
    set<string>s2;
    s2.insert("aaa");
    s2.insert("bbbb");
    s2.insert("ccccc");
    s2.insert("abb");
    s2.insert("aaa");

    auto it = s1.find(3);
    int num = s1.count(3);
    cout << "find :" << *it << endl; 
    cout << "count 3 :" << num << " ge" << endl;
    for_each(s2.begin(),s2.end(),[](const string& a) { cout << a << " ";});
    cout << endl;
    cout << "----------------------------" << endl;
    pair<set<int>::iterator , bool> ret = s1.insert(3);
    /*auto res = s1.insert(2);
    res.first;res.second;*/
    if(ret.second){
        cout << "true " << endl;
    }
    else{
        cout << "false " << endl;
    }
    cout << "test02-----------------------------" << endl;
}

void test02()
{
    multiset<int>ms1;
    ms1.insert(1);
    ms1.insert(1);
    ms1.insert(3);
    ms1.insert(2);
    for_each(ms1.begin(),ms1.end(),[](const int&a){ cout << a << " ";});
    cout << endl;
}




int main()
{
    test01();

    test02();

    return 0;
}
