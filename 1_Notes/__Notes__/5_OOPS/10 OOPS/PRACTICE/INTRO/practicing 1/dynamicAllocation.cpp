#include<iostream>
using namespace std;
class my{
    private :
    int price = 650;
    public:
    string company = "Piggion";
    bool warranty = 0;
    void TimeOfPurchase(){
        cout << "About 2 month ago i had purchased it " << endl;
    }
    int getPrice(){
        return price;
    }
};
int main(){
    cout<<endl;
    my *kettle = new my;
    cout << kettle->company << endl;
    cout << kettle->getPrice() << endl;
    kettle->TimeOfPurchase();
    
    

}