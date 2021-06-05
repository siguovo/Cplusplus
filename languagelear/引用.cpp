#include <iostream>
using namespace std;






int main()
{
	int a = 10;
	int& b = a;
	cout << a << endl;
	cout << b << endl;

	b = 20;//操控的同一个内存
	cout << a << endl;
	cout << b << endl;

	system("pause");
	return 0;
}