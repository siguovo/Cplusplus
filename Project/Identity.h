#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>


//抽象基类
class Identity
{
public:

	//menu 纯虚函数
	virtual void operMenu() = 0;
	//user
	string m_name;
	//passward
	string m_Pwd;
};

