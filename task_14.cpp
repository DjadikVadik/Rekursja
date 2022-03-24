
//  14 * .Поиск пути
//  Валера попал в лабиринт.Лабиринт представляет собой двумерный 
//  массив целых чисел MxN, некоторые элементы которого заросли 
//  непролазными джунглями(0 – свободная клетка, 1 – занятая клетка).
//  Сейчас Валера в клетке[A; B], и он хочет попасть в клетку[C; D].
//  Определите, возможно ли это, и если да – отобразите кратчайший путь следования.


#include <iostream>
#include <Windows.h>
using namespace std;

const int ROW = 20, COL = 80;
int arr[ROW][COL]{};
int hodi = -1;

void Initial()
{
	for (int i = 0; i < ROW; i++)  // создаем поле и заполняем его преградами
		for (int j = 0; j < COL; j++)
		{
			if (i == 0 || i == ROW - 1 || j == 0 || j == 1 || j == COL - 1 || j == COL - 2)
				arr[i][j] = 1;
			else if (rand() % 10 == 1)
				arr[i][j] = 1;
		}
}

void Show()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] == 1)
			{
				SetConsoleTextAttribute(h, 1);
				cout << char(219);
			}
			else if (arr[i][j] == 2)
			{
				SetConsoleTextAttribute(h, 14);
				cout << char(2);
			}
			else if (arr[i][j] == 3)
			{
				SetConsoleTextAttribute(h, 4);
				cout << char(15);
			}
			else  cout << " ";
		}
		SetConsoleTextAttribute(h, 15);
		cout << "\n";
	}
}

void PoiskPuti(int startY, int startX, int finishY, int finishX)
{
	if (arr[startY][startX + 1] == 0) arr[startY][startX + 1] = hodi;
	if (arr[startY][startX - 1] == 0) arr[startY][startX - 1] = hodi;
	if (arr[startY + 1][startX] == 0) arr[startY + 1][startX] = hodi;
	if (arr[startY - 1][startX] == 0) arr[startY - 1][startX] = hodi;

	int y1 = 0, x1 = 0;

	while(true)
	{
		for (int y = 0; y < ROW; y++)
		{
			for (int x = 0; x < COL; x++)
			{
				y1 = y;
				x1 = x;
				if (y1 == finishY && x1 == finishX && arr[y1][x1] == hodi) break;

				if (arr[y][x] == hodi && arr[y][x + 1] == 0)
					arr[y][x + 1] = hodi - 1;

				if (arr[y][x] == hodi && arr[y][x - 1] == 0)
					arr[y][x - 1] = hodi - 1;

				if (arr[y][x] == hodi && arr[y + 1][x] == 0)
					arr[y + 1][x] = hodi - 1;

				if (arr[y][x] == hodi && arr[y - 1][x] == 0)
					arr[y - 1][x] = hodi - 1;
			
			} 
			if (y1 == finishY && x1 == finishX && arr[y1][x1] == hodi) break;
		}
		if (y1 == finishY && x1 == finishX && arr[y1][x1] == hodi) break;
		else hodi--;
	}

}

void InitialPuti(int finishY, int finishX)
{
	if (hodi != 0) // рисуем путь с найменьшим количеством ходов
	{
		arr[finishY][finishX] = 3;
		if (arr[finishY - 1][finishX] == hodi + 1)
		{
			hodi++;
			InitialPuti(finishY - 1, finishX);
		}
		else if (arr[finishY + 1][finishX] == hodi + 1)
		{
			hodi++;
			InitialPuti(finishY + 1, finishX);
		}
		else if (arr[finishY][finishX - 1] == hodi + 1)
		{
			hodi++;
			InitialPuti(finishY, finishX - 1);
		}
		else if (arr[finishY][finishX + 1] == hodi + 1)
		{
			hodi++;
			InitialPuti(finishY, finishX + 1);
		}
	}
}

int main()
{
	srand(time(0));

	Initial();

	arr[10][40] = 2; // положение валеры
	int y = 4, x = 5; // координаты куда нужно добраться валере

	if (arr[y][x] != 1)
	{
		PoiskPuti(10, 40, y, x);
		cout << "Dlja dostigenija ukazannoi tichki Valere neobhodimo sdelat " << -hodi << " shagov!\n";
		InitialPuti(y, x);
	}
	else cout << "V tochke finsha pregrada!!!\n";

	Show();
}