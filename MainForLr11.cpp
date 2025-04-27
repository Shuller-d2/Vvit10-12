#include"Lr11.h"
#include<iostream>

int main() {
	int s1, s2;
	tlist<double>list1;
	tlist<double>list2;
	double chislo;
	cout << "Enter size: ";
	cin >> s1;
	for (int i = 0; i < s1; i++) {
		cout << endl << "Enter element: ";
		cin >> chislo;
		list1.push_back(chislo);
	}
	cout << "Enter size: ";
	cin >> s2;
	for (int i = 0; i < s2; i++) {
		cout << endl << "Enter element: ";
		cin >> chislo;
		list2.push_back(chislo);
	}

	cout << "Sacalar product list 1 and list 2:" << list1 * list2 << endl;
	cout << "Norma list 1 = " << list1() << " Norma list 2 = " << list2();
}