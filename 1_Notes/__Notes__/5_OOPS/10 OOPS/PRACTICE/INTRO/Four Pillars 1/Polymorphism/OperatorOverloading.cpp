#include<iostream>
using namespace std;
class param{
    public:
    int value;

    void operator+(param &object2){
            int value1 = this->value;
            int value2 = object2.value;
            cout << value2 - value1 << endl;
    }
};

int main(){
    param object1,object2;
    object1.value = 9;
    object2.value = 99;
    //THIS SHOULD PRINT THE DIFF BW 1 AND 2
    object1 + object2;
    
}