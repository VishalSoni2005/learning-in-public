#include<iostream>
using namespace std;
class Mummy{
    private:
    int age;
    string birthPlace;
    string firstChild;
    string secondChild;
    public:
    void setAge(int n){
        age = n;
    }
    int getAge(){
        return age;
    }
    void setbirthPlace(string place){
        birthPlace = place;
    }
    string getBirthPlace(){
        return birthPlace;
    }
    void setFirst(string one){
        firstChild = one;
    }
    string getFirst(){
        return firstChild;
    }
    void setSecond(string second){
        secondChild = second;
    }
    string getSecond(){
        return secondChild;
    }
};
int main(){
    cout<<endl;
    //first accessing mummy age
    Mummy neelu;
    neelu.setAge(48);
    cout << "Age of my mom is : " << neelu.getAge() << endl ;
    //second accessing her birth place
    neelu.setbirthPlace("SAHARSA");
    cout << "Birth place of my mom is : " << neelu.getBirthPlace() << endl ;
    //third accessing her first child name
    neelu.setFirst("Vishal ");
    cout << "Her first child name is : " << neelu.getFirst() << endl;
    //lastly accessing her youngest child name
    neelu.setSecond("Varun");
    cout << "Her last or youngest child name is : " << neelu.getSecond() << endl;
    cout<<endl;

}