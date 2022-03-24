
//   9. Фибоначчи.
//   Написать функцию для вычисления элементов ряда чисел Фибоначчи, 
//   исходя из рекуррентного выражения F(n) = F(n - 1) + F(n - 2).
//   Функция принимает индекс числа, возвращает значение числа.


#include <iostream>
using namespace std;

int Fibonachi(int n)
{
	if (n == 1) return 0;
	else if (n == 2) return 1;
	else if (n == 3) return 1;
	else return Fibonachi(n - 1) + Fibonachi(n - 2);
}

int main()
{
	cout << Fibonachi(14) << "\n";
}