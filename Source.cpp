#include <iostream>
using namespace std;


//#define POINTERS_BASICS
void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;        // pointer to 'a'
	cout << a << endl;
	cout << &a << endl;  //взятие адреса переменой "а" прямо при выводе 
	cout << pa << endl;  //вывод адреса переменой "а", хранящейся в указателе "pa"
	cout << *pa << endl;  //разыменование указателя "pa" и вывод на экран значения по адресу

	int* pb;
	int b = 3;
	pb = &b;      //инициализируем указатель после объявления 
#endif

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)  //вывод адресов ячеек
	{
		cout << arr + i << "\t";
	}
	cout << endl;
	for (int i = 0; i < n; i++)  //вывод значения ячеек
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
	//int* + 1B= 4B;

}