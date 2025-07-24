#include<iostream>
using namespace std;
void Array(int arr , int n){

}
int main(){
    float arr[] = {1,8,6,3.8,9};
    cout<<endl;

    cout<<arr<<endl;

    cout<<arr[0]<<" -- "<<&arr[0]<<endl;

    cout<<*arr<<endl;
    
    cout<<*arr + 1<<endl;//increase value of arr[0] to 1 ie arr[0] + 1

    cout<<*(arr + 1)<<endl;//this shows valuu of arr[0+1] IE arr[1]

    cout<<*(arr)<<endl;

    cout<<*(arr + 3) <<endl;
    cout<<endl;
    cout<<"Printing array using * method : "<<endl;
    for(int i = 0 ;i < sizeof(arr)/sizeof(arr[0]) ; i++) cout<<*(arr + i)<<" ";
    cout<<endl;
    cout<<"Remember one imp formula -> arr[i] = *(arr + i) = i[arr]"<<endl;
    cout<<"Printing in other way"<<endl;
    for(int i = 0 ;i < sizeof(arr)/sizeof(arr[0]) ; i++) cout<<i[arr]<<" ";
}