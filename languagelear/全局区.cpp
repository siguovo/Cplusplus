//#include <iostream>
//using namespace std;
//#include <string>
//
//
//int _a = 10;
//int _b = 10;
//
//const int c_g_a = 10;
//const int c_g_b = 10;
//
//
//int main()
//{
//
//	int a = 10;
//	int b = 10;
//	cout <<"局部变量a：" << (int)&a << endl;
//	cout <<"局部变量b：" << (int)&b << endl;
//
//	const int c_l_a = 10;
//	const int c_l_b = 10;
//	cout << "const修饰的局部变量c_l_a：" << (int)&c_l_a << endl;
//	cout << "const修饰的局部变量c_l_b：" << (int)&c_l_b << endl;
//	cout << endl;
//	cout << "全局变量_a：" << (int)&_a << endl;
//	cout << "全局变量_b：" << (int)&_b << endl;
//
//	cout << "const修饰的全局变量c_g_a：" << (int)&c_g_a << endl;
//	cout << "const修饰的全局变量c_g_b：" << (int)&c_g_b << endl;
//	cout << "字符串常量：" << (int)&"hello" << endl;
//	static int s_a = 10;
//	static int s_b = 10;
//	cout << "static修饰的变量s_a：" << (int)&s_a << endl;
//	cout << "static修饰的变量s_b：" << (int)&s_b << endl;
//
//	system("pause");
//	return 0;
//}