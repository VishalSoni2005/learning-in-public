#include<iostream>
using namespace std;
void change1(int x) { // pass by value
    x = 69;
}
void change2(int &x) { // pass by reference
    x = 69;
} 
int main() {
    int x = 4;
    cout << x << endl;
    change1(x) ;
    cout << x << endl;
    change2(x) ;
    cout << x << endl;
}
