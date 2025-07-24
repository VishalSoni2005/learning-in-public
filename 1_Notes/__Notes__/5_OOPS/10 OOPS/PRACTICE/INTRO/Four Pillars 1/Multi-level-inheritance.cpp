#include<iostream>
using namespace std;
class fruit{
    public: 
    string name = "Malda";
};
class mango:public fruit{
    public:
    int age;
    int Aging(int n) {
        this->age = n;
        return age;
    }
};
class Alphanso:public mango{
    public:
    string type = "AlphAnso";
    void printType() {
        cout << this->type << endl;
    }
};
int main() {
    cout << endl;
    Alphanso a ;
    a.printType();
    cout << a.Aging(3) << endl;
    cout << a.name << endl;
}