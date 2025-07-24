#include<iostream>
using namespace std;
class Animal{
    public:
    void speak(){
        cout << "speaking" << endl;
    }
};
class dog:public Animal{
    public:
    void speak() {
        cout << "Barking" << endl;
    }
};
int main() {
    dog romi;
    romi.speak();
    //JO CODE REUSABLE THA USKO USE KR LIYA AND JO NHI THA USKO OVERRIDE KR DIYA
}