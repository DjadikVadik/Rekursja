
//   5. Цифры числа справа налево.
//   Дано натуральное число N.Выведите все его цифры по одной, 
//   в обратном порядке, разделяя их пробелами.
//   При решении этой задачи нельзя использовать строки, списки, массивы
//   (ну и циклы, разумеется).Разрешена только рекурсия и целочисленная арифметика.


#include <iostream>
using namespace std;

void cifriChisla(int a)
{
	if (a >= 10)
	{
		cout << a % 10 << " ";
		a /= 10;
		cifriChisla(a);
	}
	else cout << a << "\n";
}

int main()
{
	cifriChisla(123);
}