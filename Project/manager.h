#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include<string>
#include "globalFILE.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "ComputerRoom.h"

class Manager : public Identity
{
public:
	//默认构造
	Manager();
	//有参构造
	Manager(string name, string pwd);
	//选择菜单
	virtual void operMenu();
	//添加账号
	void AddPerson();
	//查看账号
	void showPerson();

	//查看机房信息
	void showcomputer();

	//清空预约记录
	void cleanFile();

	//检测重复
	bool checkRepeat(int id, int type);

	//初始化容器
	void initVector();

	//学生容器
	vector<Student>vStu;

	//老师容器
	vector<Teacher>vTea;

	//机房容器
	vector<ComputerRoom>vCom;
};