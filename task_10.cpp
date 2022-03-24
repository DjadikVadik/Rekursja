
//   10. Степень числа.
//   Вычислить степень числа, используя рекурсию. 
//   В функцию передаётся 2 параметра - число и степень.


#include <iostream>
using namespace std;


int stepen(int chislo, int step) {

	step--;
	if (step == 0) return chislo;
	else return chislo * stepen(chislo, step);
}



int main() {

	int x = stepen(2, 4);

	cout << x << "\n\n";
	
}