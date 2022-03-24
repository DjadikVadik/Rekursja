
//   11. Сумма чисел в диапазоне.
//   Вычислить сумму чисел в определённом диапазоне.
//   Начало и конец диапазона задаётся параметрами функции.


#include <iostream>
using namespace std;


int sum(int number_1, int number_2) {

	number_1++;
	if (number_1 == number_2) return 0;
	else return number_1 + sum(number_1, number_2);
}



int main() {

	cout << sum(2, 6) << "\n\n";
}