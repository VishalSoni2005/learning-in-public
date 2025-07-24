#include<iostream>
using namespace std;
class Animal{
    public:
    int age = 15;
    string type = "Dog";
    void DD(){
        cout << "He left us in -> september 2019"<<endl;
    }
    void hisFabFood(){
        cout << "His fabourite food was Chicken and dogs candy bone "<<endl;
    }
};
int main() {
    cout << endl;
    Animal romi;
    cout<<"Who was ROMI -> "<<romi.type<<endl;
    cout<<romi.age<<endl;
    romi.hisFabFood();
    romi.DD();
}
