#include<iostream>
using namespace std;
class dost{
    private:
    int studyTime;
    int dickSize;
    public:
    int umer;
    int age() {
        return this->umer = 21;
    }
    ///////////////////////////////////
    //ACCESSING PRIVATE ASCESS MODIFIER
    int setSize() {
        return this->dickSize = 2;
    }
    int getSize() {
        return this->dickSize;
    }
};
int main() {
    dost aniket;
    cout << aniket.age() << endl;
    aniket.setSize();
    cout << aniket.getSize() << endl;
}