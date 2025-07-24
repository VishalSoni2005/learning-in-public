#include<bits/stdc++.h>
using namespace std;
class anv{
    private:
    int x;
    int *y;

    public:
    anv(){
        y = 0;
        y = new int (8);
        cout << "Value assigned, now you can provide values " << endl;
    }
    int getX() const { 
        return x;
    }
    void setX(int _val) {
        x = _val;
    }
    int getY() const{
        return *y;
    }
    void setY(int any) {
        *y = any;
    }
    
};
int main() {
    anv *a = new anv;
    a->setX(69);
    cout << a->getX() << endl;

    a->setY(96);
    cout << a->getY() << endl;

}