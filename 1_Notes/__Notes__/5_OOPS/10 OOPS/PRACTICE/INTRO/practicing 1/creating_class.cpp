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
    my kettle;
    cout << "I am having kettle of " << kettle.company << endl;
    cout << "Am i satisfied with this product ? " <<endl;
    if(kettle.warranty >= 1) cout << "yes" << endl;
    else cout << "No" <<endl;
    kettle.TimeOfPurchase();
    cout << kettle.getPrice() << endl;
}