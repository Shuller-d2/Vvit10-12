#include"Header1.h"
#include<iostream>
using namespace std;

int main() {
   
    tlist<int> list1 = { 1, 2, 3, 4 };
    list1.print();

    
    int arr[] = { 5, 6, 7 };
    tlist<int> list2(arr, 3);
    list2.print();

    
    tlist<int> list3;
    list3 = list1;
    list3.print(); 

    
    tlist<int> list4;
    list4 = move(list2);
    list4.print(); 
    list2.print(); 

    return 0;
}