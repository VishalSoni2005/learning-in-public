#include<iostream>
using namespace std;
class my{
    private:
    string relationship;
    public:
    string fullName ;
    int age;
    string nationality;
   
    string name(string name){
        return this->fullName = name;
    }
    my(){
        this->relationship = "";
        this->fullName = "";
        this->age = 0;
        this->nationality = "";
        cout << "Constructor called"<< endl;
    }
    //PARAMETREISED CONSTRUCTOR
    my(int age , string nationality){
        this->age = age;
        this->nationality = nationality;
        cout << "My age is " << age << endl;
        cout << "My nationality is " << nationality <<endl;
        cout << "Parameterised constructor is also called "<< endl;
    }
};
int main(){
    my *profile = new my;
    profile->name("Vishal kumar soni ");
    cout << profile->fullName <<endl;
    cout << endl;

    my *newProfile = new my(21 , "INDIAN");

}