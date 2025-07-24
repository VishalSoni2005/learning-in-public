#include<iostream>
using namespace std;
class abx {
    private:
    mutable int a;
    int *b;
    int c;
    public:
    abx(int _a, int _b, int _c, int _d = 0)  { // assigning _d is called default argument
        a = _a;
        b = new int(_b);
        c = _c;
        cout << "Constructor called and values have been assign" << endl;
    }
    int getA()  const{
        return a;
    }
    int getB()const {
        return *b;
    }
    int getC() {
        return c;
    }
};
void printABX(abx me){
    cout << me.getA() << " " << me.getB() << " " << me.getC() << endl;
}
int main() {
    cout << endl;
    abx me(1,2,3);
    printABX(me);
}