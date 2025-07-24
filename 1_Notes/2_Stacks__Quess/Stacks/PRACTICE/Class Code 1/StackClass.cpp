#include<iostream>
using namespace std;
class stack{
public:
    int arr[6];
    int idx = -1;
    int UparDalo(int val) {
        idx++;
        return arr[idx] = val;
    }
    void uparWalaMitao() {
        idx--;
    }
    void printDownToTop() {
        for(int i=0; i<6; i++) cout << arr[i] << " ";
    }
};
int main() {
    stack ss;
    for(int i=1; i<=6; i++) ss.UparDalo(i*12);
    ss.printDownToTop();
    cout << ss.UparDalo(2);
}