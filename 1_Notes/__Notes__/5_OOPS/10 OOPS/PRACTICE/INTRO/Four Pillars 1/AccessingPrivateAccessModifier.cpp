#include<iostream>
using namespace std;
//BY DEFAULT ACCESS MODIFIRES ARE PRIVATE
class animal{
    private:
    int weight;
    string favFood;
    public:
    void setWeight(int w){
        weight = w;
    }
    int getWeight(){
        return weight ;
    }
    void setFood(string Food){
        favFood = Food;
    }
    string getFood(){
        return favFood;
    }

};
int main(){
    animal romi;
    romi.setWeight(8);
    cout << "Romi's approx weight was ";
    cout << romi.getWeight() <<"kg"<< endl;
    string FF = "Chicken";
    romi.setFood(FF);
    cout<<"Romi's favourite Food was " << romi.getFood() << endl;
}