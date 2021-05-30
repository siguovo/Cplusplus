#include "student.h"

//默认构造
Student::Student()
{

}
//有参构造  学号 姓名 密码
Student::Student(int Id, string name, string pwd)
{
	this->m_Id = Id;
	this->m_name = name;
	this->m_Pwd = pwd;

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//菜单界面
void Student::operMenu()
{
	cout << "Welcome Student: " << this->m_name << " Login!" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         1.Apply Order           |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         2.Check My Order        |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         3.Check All Order       |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         4.Cancel Order          |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         0.Exit                  |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "Please Input your choose: ";
}

//申请预约
void Student::applyOrder()
{
	cout << "机房开放的时间为周一到周五" << endl;
	cout << "请输入预约的时间:" << endl;
	cout << "1.Monday" << endl;
	cout << "2.Tuesday" << endl;
	cout << "3.Wednesday" << endl;
	cout << "4.Thursday" << endl;
	cout << "5.Friday" << endl;
	
	int date = 0; //时间
	int interval = 0; //时间段
	int room = 0; //机房

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "Input error! Please Input again!" << endl;
	}

	cout << "请输入预约的时间段:" << endl;
	cout << "1.In the morning" << endl;
	cout << "2.In the afternoon" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "Input error! Please Input again!" << endl;
	}

	cout << "请选择机房:" << endl;
	for (int i = 0; i < 3; i++) 
	{
		cout << vCom[i].m_ComId << "号机房的容量为 :" << vCom[i].m_MaxNum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "Input error! Please Input again!" << endl;
	}
	cout << "预约成功! 审核中!" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");

}
//查看自身预约
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return; 
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))//找到自身预约
		{
			cout << "预约日期: 周" << of.m_orderData[i]["date"] << " ";
			cout << " 时间段:" << (of.m_orderData[i]["interval"] == "1" ? "Morning" : "Afternoon") << " ";
			cout << " 机房编号:" << of.m_orderData[i]["roomId"] << " ";
			string status = "状态: ";
			//1.审核中 2.已预约 -1.预约失败 4.取消预约
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中...";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "预约失败，审核未通过";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
		/*else
		{
			cout << "暂无预约记录!" << endl;
			break;
		}*/
	}
	system("pause");
	system("cls");
}
//查看所有人的预约
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << ". ";
		cout << "预约日期: 周" << of.m_orderData[i]["date"] << " ";
		cout << " 时间段:" << (of.m_orderData[i]["interval"] == "1" ? "Morning" : "Afternoon") << " ";
		cout << " 学号:" << of.m_orderData[i]["stuId"] << " ";
		cout << " 姓名:" << of.m_orderData[i]["stuName"] << "";
		cout << " 机房编号:" << of.m_orderData[i]["roomId"] << " ";
		string status = "状态: ";
		//1.审核中 2.已预约 -1.预约失败 4.取消预约
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中...";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败，审核未通过";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//取消预约
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "可取消的预约记录有:" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//判断是否是自身学号
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			//筛选状态
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << ". ";
				cout << "预约日期: 周" << of.m_orderData[i]["date"] << " ";
				cout << " 时间段:" << (of.m_orderData[i]["interval"] == "1" ? "Morning" : "Afternoon") << " ";
				cout << " 机房编号:" << of.m_orderData[i]["roomId"] << " ";
				string status = "状态: ";
				//1.审核中 2.已预约 -1.预约失败 4.取消预约
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中...";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;
	int select;

	while (true)
	{
		cin >> select;

		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "0";

				of.updateOrder();

				cout << "已取消预约" << endl;
				break;
			}
		}
		else
		{
			cout << "输入有误！请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}