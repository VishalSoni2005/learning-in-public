#include <iostream>
#include <string>
using namespace std;
int main(){
    char str[] = {'a','b','\0','d','e','f'};
    // cout<<(int)(str[6]);
    //printing through loops


    for(int i=0;str[i]!='\0';i++){
        cout<<str[i]<<" ";
    }


    //cout<<str;
}