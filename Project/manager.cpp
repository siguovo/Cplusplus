#include "manager.h"


//默认构造
Manager::Manager()
{

}
//有参构造
Manager::Manager(string name, string pwd)
{
	//初始化管理员信息
	this->m_name = name;
	this->m_Pwd = pwd;
	//初始化容器 ，获取老师和学生信息
	this->initVector();
	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "computer size  " << vCom.size() << endl;
}
//选择菜单
void Manager::operMenu()
{
	cout << "Welcome Adminstrator: " << this->m_name << " Login!" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.Add User             |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.Check User           |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.Check Computer       |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.Clear                |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.Exit                 |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "Please Input your choose: ";
}
//添加账号
void Manager::AddPerson()
{
	cout << "Please Enter The AddType:" << endl;
	cout << " 1.Add Student" << endl;
	cout << " 2.Add Teacher" << endl;

	string fileName; //操作文件名
	string tip;		//提示id
	string errortip;
	ofstream ofs; //文件操作对象

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//add student
		fileName = STUDENT_FILE;
		tip = "Please Enter Student ID:";
		errortip = "学生id重复，请重新输入";
	}
	else
	{
		//add teacher
		fileName = TEACHER_FILE;
		tip = "Please Enter Employee ID:";
		errortip = "教师id重复，请重新输入";

	}

	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;
	//添加信息
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "Please Enter Your Name: " << endl;
	cin >> name;

	cout << "Please Enter Your Passward: " << endl;
	cin >> pwd;
	
	//写入信息
	ofs << id << " " << name << " " << pwd << endl;
	cout << "Add success!" << endl;
	//调用初始化容器接口，重新获取文件信息
	this->initVector();

	system("pause");
	system("cls");
	return;

}
void PrintStudent(Student& s)
{
	cout << "Id:" << s.m_Id << "  Name:" << s.m_name << "  Passward:" << s.m_Pwd << endl;
}
void PrintTeacher(Teacher& t)
{
	cout << "EmpId :" << t.m_EmpId << "Name :" << t.m_name << "Passward :" << t.m_Pwd << endl;
}

//查看账号
void Manager::showPerson()
{
	cout << "Please select what you want to view : " << endl;
	cout << "1.View all student information" << endl;
	cout << "2.View all teacher information" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		//看学生
		cout << "All student information :" << endl;
		for_each(vStu.begin(), vStu.end(), PrintStudent);
	}
	else
	{
		//看老师
		cout << "All teacher information :" << endl;
		for_each(vTea.begin(), vTea.end(), PrintTeacher);
	}
	system("pause");
	system("cls");
}

void PrintComputer(ComputerRoom& c)
{
	cout << "ComId:" << c.m_ComId << "  MaxNum:" << c.m_MaxNum << endl;
}
//查看机房信息
void Manager::showcomputer()
{
	cout << "机房信息如下:" << endl;
	for_each(vCom.begin(), vCom.end(), PrintComputer);
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功!" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	//清空
	vStu.clear();
	vTea.clear();
	//读取学生信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "no file!" << endl;
		ifs.close();
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为 :" << vStu.size() << endl;
	ifs.close();

	// 读取老师信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "no file!" << endl;
		ifs.close();
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量为 :" << vTea.size() << endl;
	ifs.close();
}

//检测重复
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		//检测老师
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}

	return false;
}