//#include <iostream>
//using namespace std;
//
//
//int* func()
//{
//	/*int* a = new int(10);
//	return a;*/
//	//堆区 new 和 delete 使用方法
//	int* arr = new int[10];
//	return arr;
//
//}
//
//void test01() {
//
//	int* arr = func();
//	for (int i = 0; i < 10; i++) {
//		arr[i] = i + 1;
//	}
//	for (int i = 0; i < 10; i++) {
//		cout << arr[i] << endl;
//	}
//	delete[] arr;
//
//}
//int main() {
//
//	/*int* p = func();
//	cout << *p << endl;
//	cout << *p << endl;
//	cout << *p << endl;
//	cout << *p << endl;
//	delete p;*/
//	test01();
//	system("pause");
//	return 0;
//}