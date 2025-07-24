#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    //Q Print the given word in each line
    // string s = "vishal kumar soni  is a     geek ";
    // stringstream ss(s);
    // string temp;

    // while(ss>>temp){
    //     cout<<temp<<endl;
    // }

    //Q Find most occouring word in a sentence

    string s = "vishal is a champian . he studies in international institute of information technology pune . he is a geek";
    stringstream ss(s);
    string temp;
    vector<string> v;
    while(ss>>temp){
        v.push_back(temp);
    }
    //PRINTING VECTOR
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    cout<<endl;
    cout<<endl;
     
    sort(v.begin(),v.end());

    //PRINTING VECTOR AFTER SORTING
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    cout<<endl;
    cout<<endl;
}
