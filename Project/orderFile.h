#pragma once
#include <iostream>
using namespace std;
#include<fstream>
#include<string>
#include<map>
#include "globalFILE.h"

class OrderFile
{
public:
	//构造函数
	OrderFile();
	//更新预约记录
	void updateOrder();
	//记录预约条数
	int m_Size;
	//记录预约信息的容器
	map<int, map<string, string>> m_orderData;

};