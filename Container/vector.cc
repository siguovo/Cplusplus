#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;



void test01()
{
    vector<int>v1(5,1); //初始化五个1
    //遍历用iterator 
    for(vector<int>::iterator ite = v1.begin();ite != v1.end();ite++){
        cout << *ite << " ";
    }
    cout << endl;
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(2);
    //auto 自动类型推导遍历
    for(auto i : v1){
      cout << i << " ";
    }
    cout << endl;
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    //for_each算法 + lambda表达式遍历
    for_each(v1.begin(),v1.end(),[](const int&a){ cout << a << " "; });
    cout << endl;
    cout << "----------------------" << endl;
    cout << "v1.front() = " << v1.front() << endl;
    cout << "v1.back() = " << v1.back() << endl;
    cout << "v1.at(2) = " << v1.at(2) << endl;
    cout << "v1[2] = "  << v1[2] << endl;
    cout << "v1.size() = " << v1.size() << endl;
    cout << "v1.capacity() = " << v1.capacity() << endl;
    v1[0] = 2;
    int *p = v1.data(); //是一个指向vector头部的指针
    cout << "v1.data() = " << *p  << endl;
    //vector的最大容量
    cout << "v1.max_size() = " << v1.max_size() << endl;
    cout << "-------------------------------" << endl;
    vector<int>v2;
    v2.resize(v1.size());
    cout << "v2.size() = " << v2.size() << endl;
    for(auto i : v2){
      cout << i << " ";
    }
    cout << endl;
    cout << "---------------------------" << endl;
    vector<int>v3;
    //预留空间
    v3.reserve(100000);
    int num = 0;
    int *p2 = NULL;
    for(int i = 0;i < 100000;i++){
        v3.push_back(i);
        if(p2 != &v3[0]){
          p2 = &v3[0];
          num++;
        }
    }
    cout << "v3.size() = " << v3.size() << endl;
    cout << "reserve 之后开辟新空间的次数 = " << num << endl;


      
}



int main()
{
    test01();

    return 0;
}
