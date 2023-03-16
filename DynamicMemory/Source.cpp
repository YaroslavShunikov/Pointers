#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------------------\n"
//#define DynamicMemory1
#define DynamicMemory2
int** allocate(const int rows, const int cols);
void clear(int** arr, const int rows);

void FillRand(int arr[], const int n, int minRand=0, int maxRand=100);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int* Insert(int* arr, int& n, int value, int ix);			//вставляет в массив указанное значение по указанному индексу
int* PopBack(int* arr, int& n);								//удаляет последний элемент из массива
int* PopFront(int* arr, int& n);							//удаляет нудевой элемент массива
int* Irase(int* arr, int& n, int ix);						//удаляет элемент по указанному индексу

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** insert(int** arr, int& rows, const int cols,const int ix);	//вставляет в массив указанное значение по указанному индексу
int** pop_row_back(int** arr, int& rows, const int cols);			//удаляет последнюю строку
int** pop_row_front(int** arr, int& rows, const int cols);			//удаляет последнюю строку
void push_col_back(int** arr,const int rows,int& cols);
void push_col_front(int** arr,const int rows,int& cols);


void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
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
#ifdef DynamicMemory2

	int rows; //строки
	int cols; //столбцы
	cout << "Введите кол-во строк: "; cin >> rows;
	cout << "Введите кол-во эл-ов строки: "; cin >> cols;

	int** arr = allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 900, 1000);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 100, 200);
	Print(arr, rows, cols);

	int ix;
	cout << "Введите индекс добавляемой строки: "; cin >> ix;
	arr = insert(arr, rows, cols, ix);
	FillRand(arr[ix], cols, 400, 500);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	clear(arr, rows);
#endif 

}

void FillRand(int arr[], const int n, int minRand , int maxRand )
{
	for (int i = 0; i < n; i++)
	{
		//Обращение через арифметику указателей и оператор разыменования
		*(arr + i) = rand() % (maxRand-minRand)+minRand;
	}
}
int** allocate(const int rows, const int cols)
{
	int** arr = new int* [rows]; //массив указателей
	for (int i = 0; i < rows; i++)
	{
		//создаём строки
		arr[i] = new int[cols];
	}
	return arr;
}
void clear(int** arr, const int rows)
{
	//удаляем строки двумерного массива 
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//удаляем массив указателей
	delete arr;
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
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через оператор индексирования 
		//[]- оператор индексирования
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
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
int* push_back(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
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
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
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
int* Insert(int* arr, int& n, int value, int ix)
{
	int* buffer = new int[n + 1];
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
int* PopBack(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
int* PopFront(int* arr, int& n)
{
	int* buffer = new int[--n];    //С изменением значения n
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];

	}
	delete[] arr;
	return buffer;
}
int* Irase(int* arr, int& n, int ix)
{

	return arr;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int*[rows+1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new int[cols]{};
	rows ++;
	return arr;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i+1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new int [cols] {};
	rows++;
	return arr;
}
int** insert(int** arr, int& rows, const int cols, const int ix)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < ix; i++)buffer[i] = arr[i];
	for (int i = ix; i < rows; i++)buffer[i + 1] = arr[i];
	delete[]arr;
	arr = buffer;
	arr[ix] = new int[cols] {};
	rows++;
	return arr;
}
int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}
void push_col_back(int** arr,const int rows,int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j+1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;

	}
	cols++;
}
