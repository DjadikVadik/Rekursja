
//     3. Точная степень двойки.
//     Дано натуральное число N. Выведите слово YES, если число N 
//	   является точной степенью двойки, или слово NO в противном случае.
//     Операцией возведения в степень пользоваться нельзя!


#include <iostream>
using namespace std;

void stepen2(double a)
{
	if (a > 2)
	{
		a /= 2;
		stepen2(a);
	}
	else if (a < 2) cout << "NO\n";
	else cout << "YES\n";
}

int main()
{
	stepen2(8);
}