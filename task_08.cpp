
//  8. Палиндром.
//  Дано слово, состоящее только из строчных латинских букв.
//  Проверьте, является ли это слово палиндромом.Выведите YES или NO.
//  При решении этой задачи нельзя пользоваться циклами.


#include <iostream>
using namespace std;

string Palindrom(string str, int x = 0)
{
	string str_2;

	if (str[x] != '\0') str_2 = Palindrom(str, x + 1);
	else return string();

	str_2 += str[x];
	if (x == 0)
	{
		if (str == str_2) cout << "YES\n";
		else cout << "NO\n";
	}
	return str_2;
}

int main()
{
	string s = "radar";
	Palindrom(s);
}