#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    cout<<"Enter a line of letters using capital letter only : ";
    string s;
    getline(cin,s);
    //cout<<s;
    int n = s.size();

    string str;
    //Removing elements less than X
    for(int i=0;i<n;i++){
        if(s[i] >='X'){
            str.push_back(s[i]);
        }
    }
    cout<<"String after separation : "<<str<<endl;

    //Sorting
    // sort(str.begin(),str.end());

    for(int i=0;i<str.size()-1;i++){
        bool flag = true;
        for(int j=0;j<str.size()-1;j++){
            if(str[j]>str[j+1]){
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
                flag = false;
            }
        }
        if(flag == true){
            break;
        }
    }
    cout<<"String After Sorting : ";
}