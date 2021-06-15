#include<iostream>
#include<deque>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
using namespace std;



void test01()
{
    deque<int>d1;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_back(4);
    d1.push_front(5);
    d1.push_front(6);
    d1.push_front(7);
    d1.push_front(8);
    for_each(d1.begin(),d1.end(),[](const int a){ cout << a << " ";});
    cout << endl;
    sort(d1.begin(),d1.end(),[](const int&a ,const int&b){ return a > b;});
    for_each(d1.begin(),d1.end(),[](const int a){ cout << a << " ";});
    cout << endl;
    deque<int>d2;
    d2.push_back(1);
    d1.swap(d2);
    cout << "d1 : " ;
    for(auto i : d1){cout << i <<" "; }
    cout << endl;
}

void test02()
{
    queue<int>q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.pop();
    cout << q1.front() << endl;
}
void test03()
{
    stack<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.pop();
    cout << s1.top() << endl;
}



int main()
{
    test01(); 
    test02();
    test03();
    return 0;
}
