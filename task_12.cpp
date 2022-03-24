
//   12. НОД.
//   Написать рекурсивную функцию нахождения 
//   наибольшего общего делителя двух целых чисел.


#include <iostream>
using namespace std;


int NOD(int number_1, int number_2, int n = 1) 
{
	if (number_1 > number_2) swap(number_1, number_2); // определяем меньшее число, так как общий делитель не может быть больше его половины.
	n++;
	if (n <= number_1 / 2)
	{
		if (number_1 % n == 0 && number_2 % n == 0)
		{
			int x = NOD(number_1, number_2, n);
			if (n > x) return n;
			else return x;
		}
		else return NOD(number_1, number_2, n);
	}

	else return 1;

}



int main()
{
	cout << NOD(27, 9) << "\n";
}