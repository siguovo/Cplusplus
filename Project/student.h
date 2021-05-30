#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include<string>
#include <vector>
#include "ComputerRoom.h"
#include "globalFILE.h"
#include <fstream>
#include "orderFile.h"

class Student : public Identity
{
public:
	//默认构造
	Student();
	//有参构造  学号 姓名 密码
	Student(int Id, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();
	//查看自身预约
	void showMyOrder();
	//查看所有人的预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//学生学号
	int m_Id;

	//机房容器
	vector<ComputerRoom>vCom;
};
