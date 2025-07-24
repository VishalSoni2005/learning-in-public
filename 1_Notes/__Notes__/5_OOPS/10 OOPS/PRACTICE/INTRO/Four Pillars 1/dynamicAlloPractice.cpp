#include<iostream>
using namespace std;
class youtuber{
    private:
    string favJounra = "Finance and Technology";
    public:
    string FavBer = "Acharya prashant";
    void pourpose(){
        cout << "To update myself " << endl;
    }
};
int main(){
    youtuber *like = new youtuber;
    cout << like->FavBer;
}