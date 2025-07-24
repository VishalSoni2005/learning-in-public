#include<iostream>
using namespace std;
class abx{
public:
    string name;
    int age;
    string state;
    // abx(string name, int age, string state) {
    //     (*this).name = name;
    //     this->age = age;
    //     this->state = state;
    //     cout << "Ctor had called and values have been assigned" << endl;
    // }
    abx(string name, int age, string state) : name(name), age(age), state(state) { //INITIALIZATION LIST
        cout << "Ctor had called and values have been assigned" << endl;
    }
};
void change(abx *i) {
    i->name = "Aniket";
}
int main() {
    abx *i = new abx("Vishal", 21, "PUNE");
    cout << i->name << endl;    //vishal

    abx *ptr = i;
    cout << (*ptr).name << endl; //vishal

    ptr->name = "Aniket";
    cout << (*ptr).name << endl; //aniket

    change(i);
    cout << i->name << endl; //aniket
}