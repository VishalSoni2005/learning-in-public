//FAMOUS DIAMOND PROBLEM
#include<iostream>
using namespace std;
class A{
    public:
    string physics;
    string chemistry ;
    A() {
        physics = "Alakh sir";
        chemistry = "pankaj sir";
    }
};
class B{
    public:
    string maths;
    string chemistry;
    B() {
        maths = "Aashish sir";
        chemistry  = "Rohit sir";
    }
};
class C:public A , public B{
    public :
    string Exam = "JEE";
};
int main() {
    cout << endl;
    C obj;
    cout << obj.Exam << endl;
    cout << obj.maths << endl;
    cout<< obj.physics << endl;
    cout << obj.B::chemistry << endl; //SCOPE RESOLUTION OPERATOR
}