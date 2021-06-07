#include <iostream>
#include <vector>
#include <string>
#include<algorithm> 
using namespace std;

void MyPrint(vector<int>v)
{
    for(vector<int>::iterator it = v.begin();it != v.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

class Print2
{
  public:
    void operator()(int val)
    {
      cout << val << " ";
    }
};

void Print3(int v)
{
  cout << v << " ";
}

class Mycompare
{
  public:
    bool operator()(int v1,int v2)
    {
      return v1 > v2;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(3);
    v.push_back(8);
    v.push_back(2);

    //MyPrint(v);
    
    for_each(v.begin(),v.end(),Print3);//所有值打印
    sort(v.begin(),v.end()); 
    cout << endl;
    for_each(v.begin(),v.end(),Print2());//升序打印
    cout << endl;
    sort(v.begin(),v.end(),Mycompare()); //添加一个谓词
    for_each(v.begin(),v.end(),Print2());//降序打印
    cout << endl;


    //lambda
    sort(v.begin(),v.end(),[](const int &a,const int &b)->int{ return a < b; });
    for_each(v.begin(),v.end(),[](const int &a){ cout << a << " ";});
    cout << endl;

}


int main()
{
  test01();

  return 0;
}
