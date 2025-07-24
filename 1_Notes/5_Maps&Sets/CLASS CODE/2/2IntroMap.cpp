#include<iostream>
#include<map>
using namespace std;
int main() {
    map<int , int>m;

    m[1] = 30;
    m[3] = 10;
    m[2] = 20;

    for(auto i : m) {
        cout << i.first << " -> " << i.second << endl;
    }

    cout << endl;

    map<string, int>mark;
    mark["Vishal"] = 2;
    mark["Aniket"] = 1;
    mark["Jay Arora"] = 8;

    for(auto j : mark) {    //sort via lexcographical order
        cout << j.first << " -> " << j.second << endl;
    }
 
}