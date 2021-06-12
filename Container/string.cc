#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <fstream>
using namespace std;

//init
void test01()
{
    string s1("abcdefghijklmnopqrstuvwxyz");
    cout << s1 << endl;
    cout << "function ---------------------" << endl;
    cout << "s1.front() = " << s1.front() << endl;
    cout << "s1.back() = " << s1.back() << endl;
    cout << "s1.capacity() = " << s1.capacity() << endl;
    cout << "s1.size() = " << s1.size() << endl;
    cout << "s1.at(2) = " << s1.at(2) << endl;
    cout << "s1[2] = " << s1[2] << endl;
    cout << "+=---------------------" << endl;
    string s2 = "aaa";
    string s3(3,'b');
    s2 += s3;
    cout << "s2 = " << s2 << endl;
    s3.append(s2);
    cout << "s3 = " << s3 << endl;
    s2.append("ccc");
    cout << "s2 = " << s2 << endl;
    cout << "find---------------------" << endl;
    //find   从前往后找  find ---->
    string s4 = "abcdefghdef";
    int pos = s4.find("def");//返回第一个字符的下标，没找到返回-1;
    int pos2 = s4.find("af");
    cout << "find pos = " << pos << endl;
    cout << "pos2 = " << pos2 << endl;
    //rfind
    pos = s4.rfind("def"); //从后往前找    <----rfind 
    cout << "rfind pos = " << pos << endl;
    cout << "replace---------------------" << endl;
    //replace
    s4.replace(1,3,"111"); //从1位置 往后三个替换为111
    cout << "replace s4 = " << s4 << endl;
    cout<< "compare----------------------" << endl;
    string s5 = "hello";
    string s6 = "hello";
    int res = s5.compare(s6); // == res->0  |   > res->1  |   < res->-1
    cout << "res = " << res << endl;
    cout << "insert----------------------" << endl;
    s5.insert(1,"666");
    cout << "insert s5 = " << s5 << endl;
    cout << "erase----------------------" << endl;
    s5.erase(1,3);
    cout << "erase s5 = " << s5 << endl;
    cout << "clear----------------------" << endl;
    s5.clear();
    cout << "s5.claer() = " << s5 << endl;
    //substr  截取子串
    cout << "substr---------------------" << endl;
    string s7 = "dm411554844@163.com";
    int pos4 = s7.find("@");
    string username = s7.substr(0,pos4);
    cout << "substr username = " << username << endl;



}


int main()
{
    test01();
    return 0;
}
