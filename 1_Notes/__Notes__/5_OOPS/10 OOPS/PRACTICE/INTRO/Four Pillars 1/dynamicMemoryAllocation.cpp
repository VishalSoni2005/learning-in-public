#include<iostream>
using namespace std;
class laptop{
    public:
    string type = "HP";
    int price = 40'000;
    void uses(){
        cout << "Majorly for coding pourpose " <<endl;
    }
    string phone(string model){
        model  = "OPPO RENO";
        return model;
    }
};
int main(){
    cout << endl;
    laptop* aniket = new laptop;//here aniket contain the address in static memeory which contain data member of new laptop
    cout << (*aniket).type << endl;//using dereference operator we can assess the content in class having in new laptop data member
    cout<< (*aniket).price <<endl;
    cout<<endl;
    aniket->price = 25'000;
    cout << (*aniket).price << endl;
    aniket->type = "DELL";
    cout << aniket->type << endl;
    cout << endl;
    cout << aniket->phone("") <<endl;
    aniket->uses();

}