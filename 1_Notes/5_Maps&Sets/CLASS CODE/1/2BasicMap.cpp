#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
    unordered_map<string, int>m;    //maps always accept pairs;

    //1
    pair<string, int>vishal;
    vishal.first = "Vishal";
    vishal.second = 64;
    
    //2
    pair<string, int>aniket;
    aniket.first = "Aniket";
    aniket.second = 6;

    //3
    pair<string, int>jay;
    jay.first = "Jay Aroro";
    jay.second = 3;

    m.insert(vishal);
    m.insert(jay);
    m.insert(aniket);

    for(auto p : m) { // we can write {pair<string, int>} in place fo outo
        cout << p.first << " -> " << p.second << endl;
    }
}