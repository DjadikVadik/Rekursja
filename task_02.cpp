
//    2. От A до B.
//    Даны два целых числа A и В. Выведите все числа от A до B включительно, 
//    в порядке возрастания, если A < B, или в порядке убывания в противном случае.


#include <iostream>
using namespace std;

void chisla(int a, int b)
{
	if (a < b)
	{
		cout << a << "\t";
		a++;
		chisla(a, b);
	}
	else if (a > b)
	{
		cout << a << "\t";
		a--;
		chisla(a, b);
	}
	else cout << a;
}

int main()
{
	chisla(6, 1);
	cout << "\n\n";
}