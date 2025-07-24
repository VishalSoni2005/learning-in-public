#include<bits/stdc++.h>
using namespace std;
class hero{
    public:
    int health;
    string name;
    string feild;

    int fitnessLevel(){
        this->health = 90;
        return this->health;
    }
    string nam() {
        return this->name = "SAM MANIK SHAW";
    }
    string work() {
        return this->feild = "ARMY";
    }
};
int main() {
    hero sam;
    cout << sam.fitnessLevel() << endl;
    cout << sam.nam() << endl;
    cout << sam.work() << endl;

}