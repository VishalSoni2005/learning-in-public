#include<iostream>

class Animal {
    public:
    virtual void speak() {
        std::cout << "Speaking" << std::endl;
    }
};
class Dog:public Animal {
    public:
    void speak() {
        std::cout << "Barking" << std::endl;
    }
};
int main() {
    //UPCASTING
    Animal* Romi = new Dog();
    Romi->speak();
    //DOWNCASTING
    Dog* Tomy = (Dog*)new Animal();
    Tomy->speak();
}