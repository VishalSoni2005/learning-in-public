#include<iostream>
using namespace std;
class my{
    private:
    int carPrice = 2'00'00'000;
    public:
    string carType = "MERCEDECE";
    string carModel = "G-WAGON";
    int yearOfPurchase = 2026;
    int setPrice(){
        return carPrice;
    }
    void getPrice(int price){
        int cash = price; 
    }

};
int main(){
    my car;
    cout<<car.carType<<endl;
    cout<<car.carModel<<endl;
    car.setPrice();
    car.getPrice(2);
}