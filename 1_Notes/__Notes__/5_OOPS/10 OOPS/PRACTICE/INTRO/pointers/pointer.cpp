#include<iostream>
using namespace std;
int main(){
    // cout<<"/////////////////////////////////////////////////////////////////////"<<endl;
    // int num = 12;
    // cout<<"You number is : "<<num<<endl;
    // cout<<"Address of stored number is : "<<&num<<endl;
    // int *ptr = &num;
    // cout<<"POINTER STORES THE ADDRESS OF NUMS AND POINTER HAVE ITS OWN ADDRESS (CONTENT IN PTR IS ADDRESS OF NUM)"<<endl;
    // cout<<"Address of num box is : "<<ptr<<endl;
    // cout<<"Address of pointer ptr is : "<<&ptr<<endl;
    // cout<<"/////////////////////////////////////////////////////////////////////"<<endl;
    // int *q = &num;
    // cout<<q<<endl;

    int a = 8;
    cout<<a<<endl;
    int *p = 0;
    p = &a;
    cout<<p<<endl;
    (*p)++;
    cout<<a<<endl;
    //copying a pointer
    int *b = p;
    cout<<b<<" -- "<<p<<endl;
    cout<<*b<<" -- "<<*p<<endl;    
}