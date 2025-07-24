#include<bits/stdc++.h>
using namespace std;
int main() {
    unordered_map<char, int> m;
    string s = "Vishal";
    string t = "Soni";

    for(auto i : s) m[i]++;
    for(auto j : t) m[j]--;

    for(auto x : m) if(x.second != 0) {
        cout << "False" << endl;
        cout << x.first << " " << x.second;
    }

    // for(auto )ṇ
}