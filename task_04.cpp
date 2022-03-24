
//    4. Сумма цифр числа.
//    Дано натуральное число N.Вычислите сумму его цифр.
//    При решении этой задачи нельзя использовать строки, 
//    списки, массивы, глобальные переменные(ну и циклы, разумеется).



#include <iostream>
using namespace std;

int sumChisel(int a, int sum = 0)
{
	if (a >= 10)
	{
		sum += a % 10;
		a /= 10;
	    sumChisel(a, sum);
	}
	else
	{
		sum += a;
		return sum;
	}
}

int main()
{
	cout << sumChisel(1209) << "\n\n";
}