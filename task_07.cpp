
//   7. Разворот числа.
//   Дано число n, десятичная запись которого не содержит нулей.Получите число, 
//   записанное теми же цифрами, но в противоположном порядке.При решении этой 
//   задачи нельзя использовать циклы, строки, списки, массивы, разрешается только 
//   рекурсия и целочисленная арифметика.Функция должна возвращать целое число, 
//   являющееся результатом работы программы, выводить число по одной цифре нельзя.



#include <iostream>
using namespace std;

int cifriChisla(int a, int sum = 0)
{
	if (a >= 10)
	{
		sum = (sum + (a % 10)) * 10;
		cifriChisla(a / 10, sum);
	}
	else
	{
		sum += a % 10;
		return sum;
	}
}

int main()
{
	cout << cifriChisla(3784) << "\n";
}