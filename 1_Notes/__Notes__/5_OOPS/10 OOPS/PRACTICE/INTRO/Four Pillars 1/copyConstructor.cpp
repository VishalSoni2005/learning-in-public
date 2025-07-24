#include<iostream>
using namespace std;
class Everthing{
    private:
    bool car;
    int netWorth;
    public:
    string conditon;
    int studingHrs;


    void setCar(bool flag){
        this->car = flag;
    }
    void getCar(){
        if(car == true) cout << "Having" << endl;
        if(car == false) cout << "Not having" << endl; 
    }
    void setWorth(int worth){
        this->netWorth = worth;
    }
    int getWorth(){
        return netWorth;
    }


};
int main(){
    Everthing *ok = new Everthing;
    ok->conditon = ("SAB CHANGA SI");
    ok->studingHrs = 3;
    ok->setCar(1);
    ok->getCar();
    ok->setWorth(1'000'000);
    ok->getWorth();

    
}