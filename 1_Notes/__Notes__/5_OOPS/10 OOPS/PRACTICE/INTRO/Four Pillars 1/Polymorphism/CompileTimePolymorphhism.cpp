#include<iostream>
using namespace std;
class maths{
    public:
    int sum(int a , int b) {
        return a+b ;
    }
    int sum(char a , char b) {
        return int(a+b);
    }
};
int main() {
    maths obj;
    //cout << sum(7,9) << endl;
    //cout << sum('a' , 'b') << endl;

}