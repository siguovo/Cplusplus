#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <utility>
using namespace std;


void test05()
{
    cout << "----------map---------------" << endl;
    map<string,int> m1;
    m1.insert({"duanmao",1001});
    m1.insert({"duanmao",1005});
    m1.insert(make_pair("zhangsan",1002));
    m1.insert(pair<string,int>("lisi",1003));
    m1.insert(map<string,int>::value_type("wangwu",1004));

    for(const auto i : m1){
        cout << "姓名:" << i.first << "  编号:" << i.second << endl;
    }
    cout << endl;
    cout << "----------multimap---------------" << endl;
    multimap<string,int> m2;
    m2.insert({"duanmao",1001});
    m2.insert({"duanmao",1005});
    m2.insert(make_pair("zhangsan",1002));
    m2.insert(pair<string,int>("lisi",1003));
    m2.insert(map<string,int>::value_type("wangwu",1004));

    for(const auto i : m2){
        cout << "姓名:" << i.first << "  编号:" << i.second << endl;
    }
    cout << endl;
    cout << "----------unordered_map---------------" << endl;
    unordered_map<string,int> m3;
    m3.insert({"duanmao",1001});
    m3.insert({"duanmao",1005});
    m3.insert(make_pair("zhangsan",1002));
    m3.insert(pair<string,int>("lisi",1003));
    m3.insert(map<string,int>::value_type("wangwu",1004));

    for(const auto i : m3){
        cout << "姓名:" << i.first << "  编号:" << i.second << endl;
    }
    cout << endl;
    cout << "----------unordered_multimap---------------" << endl;
    unordered_multimap<string,int> m4;
    m4.insert({"duanmao",1001});
    m4.insert({"duanmao",1005});
    m4.insert(make_pair("zhangsan",1002));
    m4.insert(pair<string,int>("lisi",1003));
    m4.insert(map<string,int>::value_type("wangwu",1004));

    for(const auto i : m4){
        cout << "姓名:" << i.first << "  编号:" << i.second << endl;
    }
    cout << endl;
}




void test04()
{
    cout << "--------set------------" << endl;
    set<string>s1;
    s1.insert("hello");
    s1.insert("word");
    s1.insert("hello");
    s1.insert("word");
    for(auto i : s1){
        cout << i << " ";
    }
    cout << endl;

    cout << "--------multiset------------" << endl;
    multiset<string>s2;
    s2.insert("hello");
    s2.insert("word");
    s2.insert("hello");
    s2.insert("word");
    for(auto i : s2){
        cout << i << " ";
    }
    cout << endl;

    cout << "--------unordered_set------------" << endl;
    unordered_set<string>s3;

    s3.insert("hello"); //会计算一个hash值，将其存储
    s3.insert("word");
    s3.insert("hello");
    s3.insert("word");
    for(auto i : s3){
        cout << i << " ";
    }
    cout << endl;

    cout << "--------unordered_multiset------------" << endl;
    unordered_multiset<string>s4;

    s4.insert("hello"); //会计算一个hash值，将其存储
    s4.insert("word");
    s4.insert("hello");
    s4.insert("word");
    for(auto i : s4){
        cout << i << " ";
    }
    cout << endl;
}



void test03()
{
    set<string>s1;
    s1.insert("hello");
    s1.insert("hello");
    s1.insert("word");
    set<string>::iterator si = s1.begin();
    if(si != s1.end()){
        cout << *si << " ";
    }
    cout << endl;

    for(set<string>::iterator si = s1.begin();si != s1.end();si++){
        cout << *si << " ";
    }
    cout << endl;
    cout << "---------------------------------" << endl;
    for(auto i : s1){
        cout << i << " ";
    }
    cout << endl;
}


vector<int> test02()
{
    vector<int>v1{1,2,3,4,5,4,6,7,4,4};
    map<int,pair<int,int> >m1;
    int len = v1.size();
    vector<int>res;
    for(int i = 0; i < len; i++){
        if(m1[v1[i]].first != 0){
            res.push_back(i);
        } else {
            m1[v1[i]].first++;
            m1[v1[i]].second = i;
        }
    }
    return res;
}



void test01()
{
    unordered_map<string,size_t>word_count;
    string word;
    int counts = 5;
    while(cin >> word){
        counts--;
        word_count[word] = word_count[word] + 1;
        if(counts == 0) break;
    }
    for(const auto &i : word_count){
        cout << i.first << "出现的次数为 ： " << i.second << endl;
    }
}



int main(void)
{

    //test01();
    /*vector<int> t = test02();
    for(auto i : t){
        cout << i << " ";
    }
    cout << endl;*/
    test05();
    return 0;
}
