
//   13 * .Черепашка.
//   На квадратной доске размером NxN расставлены случайные целые 
//   положительные числа.Черепашка, находящаяся в левом верхнем углу, 
//   мечтает попасть в правый нижний.При этом она может переползать 
//   только в клетку справа или снизу(не наискосок) и хочет, чтобы 
//   сумма всех чисел, оказавшихся у неё на пути, была максимально 
//   возможной.Показать на экране консоли эту сумму.Также, программа 
//   должна показать путь следования черепашки.



#include <iostream>
#include <windows.h>
using namespace std;


void sumChisel(int* arr[], int row, int& a, int y = 0, int x = 0, int sum_1 = 0, int sum_2 = 0)
{
	if (y < row && x < row)
	{
		sum_1 += arr[y][x];
		sumChisel(arr, row, a, y + 1, x, sum_1, sum_2);

		sum_2 += arr[y][x];
		sumChisel(arr, row, a, y, x + 1, sum_1, sum_2);

		if (y == row - 1 && x == row - 1)
		{
			if (sum_1 > sum_2 && sum_1 > a) a = sum_1;
			else if (sum_2 > sum_1 && sum_2 > a) a = sum_2;
		}
	}
}

void Puti(int* arr[], int row, int& a, int y = 0, int x = 0, int sum_1 = 0, int sum_2 = 0)
{
	if (y < row && x < row)
	{
		sum_1 += arr[y][x];
		Puti(arr, row, a, y + 1, x, sum_1, sum_2);

		sum_2 += arr[y][x];
		Puti(arr, row, a, y, x + 1, sum_1, sum_2);

		if (sum_1 == a || sum_2 == a)
		{
			a -= arr[y][x];
			arr[y][x] = 0;
		}
	}
}



int main()
{
	system("chcp 1251 > 0");

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	const int SIZE = 5;   // создаем массив 
	int arr[SIZE][SIZE];

	for (int i = 0; i < SIZE * SIZE; i++)  //заполняем его случайными числами
		arr[0][i] = rand() % 50 + 1;

	arr[0][0] = 0;   // выставляем черепашку в верхний левый угол

	cout << "Доска с черепашкой вначале пути:\n\n";
	for (int i = 0; i < SIZE; i++)       // покзываем масив с черепашкой                 
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i][j] == 0)
			{
				SetConsoleTextAttribute(h, 12);
				cout << "#" << "\t";
			}
			else cout << arr[i][j] << "\t";
			SetConsoleTextAttribute(h, 15);
		}
		cout << "\n";
	}

	int* pArr[SIZE];                    // создаем массив указателей для передачи любого двумерного массива в функцию
	for (int i = 0; i < SIZE; i++)
		pArr[i] = arr[i];

	int a = 0;     // переменная для хранения суммы чисел на пути черепашки

	sumChisel(pArr, SIZE, a);      // проверяем все возможные пути черепашки и записываем в переменную найбольшую сумму
	cout << "\nНайбольая сумма чисел, которую может собрать черепашка: " << a << "\n\n";

	Puti(pArr, SIZE, a);      // ресуем путь черепашки, на котором она собрала найбольшую сумму

	cout << "Путь которым прошла черепашка : \n";   // показываем путь, которым прошла черепашка
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i][j] == 0)
			{
				SetConsoleTextAttribute(h, 12);
				cout << "#" << "\t";
			}
			else cout << arr[i][j] << "\t";
			SetConsoleTextAttribute(h, 15);
		}
		cout << "\n";
	}
}