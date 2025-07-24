#include<iostream>
using namespace std;
int main() {

    //TYPE 1

    //CONST WITH POINTERS 
    // int *a = new int;
    // *a = 2;
    // cout << *a << endl;
    // int b = 5;
    // a = &b;
    // cout << *a << endl;

    //TYPE 2 , CONST DATA , NON CONST DATA TYPE

    // const int *a = new int (2); 
    // cout << a << endl; //IT WILL GIVE ME THE ADDRESS OF BOX HAVING VALUE OF A
    // cout << &a << endl; // THIS WILL GIVE ME THE ADDRESS OF THE POINTER
    // cout << *a << endl; // GIVE THE VALUE CONTAINED IN THE BOX OF HEAP MEMORY
    // int b = 99;
    // a = &b; // PONTER CAN BE REASSIGNED
    // cout << *a << endl;

    //TYPE 3 
    //CONST POINTER , BUT NON-CONST DATA
    // int *const a = new int(2);
    // cout <<"value duning initial -> " << *a << " - and address is -> " << a << endl;
    // int b = 9;
    // *a = b; //VALUE OF POINTER IS CHANGED
    // cout << "value after modify -> " << *a << " ans its address>" << a << endl;

    //TYPE 4
    // const pointer and constant value
    const int *const a = new int(3);
    cout << a << " and " << *a << endl;
    
}