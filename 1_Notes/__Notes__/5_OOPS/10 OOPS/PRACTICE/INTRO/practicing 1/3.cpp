#include<iostream>
using namespace std;
class address{
    private :
    int pinCode;
    public:
    string state = "MAHARASTRA";
    string city = "PUNE";

    void fullAdd() {
        cout << "Sivaji chowk, Hinjewadi, pune - 411057" << endl;
        return;
    }
    int setPin(int k) {
        return this->pinCode = k;
    }
    void getPin() {
        cout << "PinCode is " << this->pinCode << endl;
    }
};
int main() {
    address *my = new address;
    my->fullAdd();
    cout << my->city << endl;
    cout << my->state << endl;
    my->setPin(411057);
    my->getPin();
}