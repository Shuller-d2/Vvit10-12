#include "Lr12.h"
#include<iostream>
using namespace std;

int main() {
    tlist<double> list1;
    tlist<double> list2;
    cout << "Enter size: ";
    int i1;
    cin >> i1;
    for (int j = 0; j < i1; j++) {
        cout << "Enter elevent:";
        double chislo;
        cin >> chislo;
        list1.push_back(chislo);
    }
    cout << "Enter size: ";
    int i2;
    cin >> i2;

    for (int j = 0; j < i2; j++) {
        cout << "Enter elevent:";
        double chislo;
        cin >> chislo;
        list2.push_back(chislo);
    }
    cout << endl;
    cout << "Summa list 1 and list 2: " << endl;
    tlist<double> list3 = list1 + list2;
    list3.print();
    cout << "Diffrent list 1 and list 2" << endl;
    tlist<double> list4 = list1 - list2;
    list4.print();
    cout << "list 1 add list 2:" << endl;
    list1 += list2;
    list1.print();
    list1 -=list2;
    cout << "list 1 substract list 2" << endl;
    list1.print();
    return 0;
}