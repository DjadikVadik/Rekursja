
//    1. От 1 до n.
//    Дано натуральное число n. Выведите все числа от 1 до n.


#include <iostream>
using namespace std;

void chisla(int n, int x = 0)
{
	x++;
	cout << x << "\t";
	if (x == n) return;
	else chisla(n, x);
}

int main()
{
	chisla(6);
	cout << "\n\n";
}