#include<iostream>
using namespace std;
class my{
    private:
    int cost = 30'000;
    public:
    string model(string phone){
        phone  = "REDMI K20 PRO ";
        return phone ;
    }
    void purpose(){
        cout << "I majorly use my phone to instagram and to call " << endl;
    }
    int getCost(){
        return cost;
    }
};
int main(){
    cout << endl;
    my *phone = new my;
    cout << phone->model("") << endl;
    phone->purpose();
    cout << phone->getCost();
}