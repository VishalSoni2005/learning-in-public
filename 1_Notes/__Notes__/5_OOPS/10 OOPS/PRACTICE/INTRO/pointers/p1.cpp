#include<iostream>
using namespace std;
void helper(int *arr) {
    cout << arr << endl;
    for(int i=0;i<3;i++) {
        cout << *(arr + i) << " ";
    }
}
int main() {
    int i = 20;
    cout << &i << endl;
    int *ptr = &i;
    cout << ptr;
    //int arr[] = {1,2,3};
    //cout << arr <<endl;
    //helper(arr);
}