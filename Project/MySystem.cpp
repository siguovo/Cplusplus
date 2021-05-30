#include <iostream>
using namespace std;
#include "Identity.h"
#include <fstream>
#include <string>
#include "globalFILE.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

//进入学生子菜单
void studentMenu(Identity*& student)
{
	while (true)
	{
		//调用子菜单
		student->operMenu();
		//将父类指针转为子类指针
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1) //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有人预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else //注销
		{
			delete student;
			cout << "Log out!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//进入教师子菜单
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用教师菜单
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		if (select == 1)//查看所有预约
		{
			tea->showAllOrder();
		}
		else if (select == 2)//审核预约
		{
			tea->validOrder();
		}
		else
		{
			//注销
			delete teacher; //销毁堆区对象
			cout << "Log out!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//进入管理员子菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管路员子菜单
		manager->operMenu();

		//将父类指针转为子类指针
		Manager* man = (Manager*)manager;

		int select = 0;
		//接收用户选项
		cin >> select;

		if (select == 1)//添加账号
		{
			//cout << "添加" << endl;
			man->AddPerson();
		}
		else if (select == 2)//查看账号
		{
			//cout << "查看 " << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			//cout << "机房 " << endl;
			man->showcomputer();
		}
		else if (select == 4)//清空预约
		{
			//cout << "清空" << endl;
			man->cleanFile();
		}
		else
		{
			//注销
			delete manager; //销毁堆区对象
			cout << "Log out!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//登录
void LoginIt(string filename, int type)
{
	//父类指针，指向子类
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "no file!" << endl;
		ifs.close();
		return;
	}

	//准备接收用户信息
	int id = 0;
	string name;
	string pwd;

	//student
	if (type == 1)
	{
		cout << "Please Enter The Student ID:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "Please Enter The Employee ID:" << endl;
		cin >> id;
	}
	cout << "Please Enter Username:" << endl;
	cin >> name;

	cout << "Please Enter Passward:" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//student验证
		int fId;	//文件中的学生id
		string fName;	//文件中的学生姓名
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//比较
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "Login successful!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生的子菜单
				studentMenu(person);
				return;
			}
			/*else
			{
				cout << "输入有误！" << endl;
				system("pause");
				system("cls");
				return;
			}*/
		}

	}
	//teacher验证
	else if (type == 2)
	{
		//teacher验证
		int fId;	//文件中的老师id
		string fName;	//文件中的老师姓名
		string fPwd;	//密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//比较
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "Login successful!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师的子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	//admin验证
	else if (type == 3)
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "Login successful!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员菜单
				managerMenu(person);
				return;
			}
		}
	}
	
	cout << "Login Failed!" << endl;
	system("pause");
	system("cls");
	return;
}


int main()
{
	int select = 0;

	while (true)
	{
		cout << "=====================================welcome to the system of servation=====================================" << endl;
		cout << "Please enter your identity" << endl;
		cout << "\t\t ---------------------------------\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           1.Student             |\n ";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           2.Teacher             |\n ";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           3.Adminstrator        |\n ";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           0.Exit                |\n ";
		cout << "\t\t|                                 |\n";
		cout << "\t\t ---------------------------------\n";
		cout << "Please Input your choose: ";

		cin >> select;   //user Input

		switch (select) 
		{
		case 1:		//student
			LoginIt(STUDENT_FILE, 1);
			break;
		case 2:		//teacher
			LoginIt(TEACHER_FILE, 2);
			break;
		case 3:		//adminstrator
			LoginIt(ADMIN_FILE, 3);
			break;
		case 0:		//exit
			cout << "Welcome to use next time!" << endl;
			system("pause");
			return 0;
			break;
		default:	//error
			cout << "Input error! Please choose again!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}