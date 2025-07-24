#include<iostream>
#include<string.h>
using namespace std;
class Animal{
    public:
    string name;

    void eat(){
        cout << "Eating" << endl;
    }
    string nam(string str){
        this->name = str;
        return this->name;
    }
    void print() {
        cout << this->name << endl;
    }
};
class my:protected Animal{
    public:
    void print() {
        cout << "My Pet name is : " << name << endl;
    }
};
int main(){
    Animal cat;
    cout << cat.nam("PUSSY");
    // my dog;
    // dog.print();
    my romi;
    romi.print();
}