#include<bits/stdc++.h>
using namespace std;
int main() {
    unordered_map<string, int> m;

    m["Vishal"] = 64;   // KEY AND VALUE GET ASSIGNED AND INSERTED ALSO
    m["Aniket"] = 8;    // KEY AND VALUE GET ASSIGNED AND INSERTED ALSO ((.)(.))
    m["Jay Arora"] = 3; // KEY AND VALUE GET ASSIGNED AND INSERTED ALSO
    m["Hari"] = 55;     // KEY AND VALUE GET ASSIGNED AND INSERTED ALSO

    for(auto p : m) {
        cout << p.first << " -> " << p.second << endl;
    }
    cout << " After Deletion : "<< endl;
    m.erase("Hari");    //only key is required not value to erase;
    for(auto p : m) {
        cout << p.first << " -> " << p.second << endl;
    }
}