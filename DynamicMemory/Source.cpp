#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------------------\n"
template<typename T>T** allocate(const int rows, const int cols);
template<typename T>void clear(T** arr, const int rows);

void FillRand(int arr[], const int n, int minRand=0, int maxRand=100);
void FillRand(int** arr, const int rows, const int cols);

template<typename T>void Print(T* arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T* arr, int& n, T value);
template<typename T>T* push_front(T* arr, int& n, int value);
template<typename T>T* Insert(T* arr, int& n, T value, int ix);			//вставляет в массив указанное значение по указанному индексу
template<typename T>T* PopBack(T* arr, int& n);								//удаляет последний элемент из массива
template<typename T>T* PopFront(T* arr, int& n);							//удаляет нудевой элемент массива
template<typename T>T* Irase(T* arr, int& n, int ix);						//удаляет элемент по указанному индексу

template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** push_row_front(T** arr, int& rows, const int cols);
template<typename T>T** insert_row(T** arr, int& rows, const int cols,const int ix);	//вставляет в массив указанное значение по указанному индексу
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);			//удаляет последнюю строку

template<typename T>void push_col_back(T** arr,const int rows,int& cols);

//#define DynamicMemory1
#define DynamicMemory2
void main()
{
	setlocale(LC_ALL, "");
#ifdef DynamicMemory1
	int n;
	cout << "Введите кол-во эл-ов:"; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr=push_back(arr, n, value);
	Print(arr, n);
	

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	int ix;
	cout << "Введите индекс добавляемого значения: "; cin >> ix;
	arr = Insert(arr, n, value, ix);
	Print(arr, n);

	arr = PopBack(arr, n);
	Print(arr, n);

	arr = PopFront(arr, n);
	Print(arr, n);

	delete[] arr;
#endif

	int rows; //строки
	int cols; //столбцы
	cout << "Введите кол-во строк: "; cin >> rows;
	cout << "Введите кол-во эл-ов строки: "; cin >> cols;

	int** arr = allocate<int>(rows,cols);

	FillRand(arr,rows, cols);
	Print(arr,rows, cols);
	cout << delimiter << endl;
	arr=push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 900, 1000);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 100, 200);
	Print(arr, rows, cols);

	int ix;
	cout << "Введите индекс добавляемой строки: "; cin >> ix;
	arr = insert_row(arr, rows, cols, ix);
	FillRand(arr[ix], cols, 400, 500);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	clear(arr, rows);
}


template<typename T>T** allocate(const int rows, const int cols)
{
	T** arr = new T* [rows]; //массив указателей
	for (int i = 0; i < rows; i++)
	{
		//создаём строки
		arr[i] = new int[cols];
	}
	return arr;
}
template<typename T>void clear(T** arr, const int rows)
{
	//удаляем строки двумерного массива 
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//удаляем массив указателей
	delete arr;
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//Обращение через арифметику указателей и оператор разыменования
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через оператор индексирования 
		//[]- оператор индексирования
		cout << arr[i] << tab;
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
template<typename T>T* push_back(T* arr, int& n, T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
template<typename T>T* push_front(T* arr, int& n, T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
template<typename T>T* Insert(T* arr, int& n, T value, int ix)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		if (i < ix)buffer[i] = arr[i];
		else buffer[i + 1] = arr[i];
	}
	buffer[ix] = value;
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}
template<typename T>T* PopBack(T* arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
template<typename T>T* PopFront(T* arr, int& n)
{
	T* buffer = new T[--n];    //С изменением значения n
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];

	}
	delete[] arr;
	return buffer;
}
template<typename T>T* Irase(T* arr, int& n, int ix)
{

	return arr;
}
template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T*[rows+1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new T[cols]{};
	rows ++;
	return arr;
}
template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i+1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new T [cols] {};
	rows++;
	return arr;
}
template<typename T>T** insert_row(T** arr, int& rows, const int cols, const int ix)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < ix; i++)buffer[i] = arr[i];
	for (int i = ix; i < rows; i++)buffer[i + 1] = arr[i];
	delete[]arr;
	arr = buffer;
	arr[ix] = new T[cols] {};
	rows++;
	return arr;
}
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>void push_col_back(T** arr,const int rows,int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
