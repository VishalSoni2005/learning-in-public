#include<iostream>
#include<vector>
using namespace std;
class queue{
public:
    int f;  //fornt index
    int b;  //back index
    int size;       //IT IS BASICALLY (f - b)
    vector<int> arr;
    queue(int val) {
        f = 0;
        b = 0;
        size = 0;
        vector<int> v(val);
        arr = v;
    }
    //INITIALY BOTH INDEXES ARE AT 0TH POSITION
    // BTH INDEX WILL MOVE FORWARD AS TO MAKE FILO**
    void push(int val) {
        if(b == size) {
             cout << "Queue Is Full" << endl;
             return ;
        }
        arr[b] = val;
        b++;
        size++;
    }

    void pop() { //FOR POPING JUST MOVE FRONT INDEX 
        if(size == 0) {
            cout << "Queue is Empty !" << endl;
            return ;
        }
        f++;
        size--;
    }

    int front() {
        if(size == 0) {
            cout << "Empty";
            return -1;
        }
        return arr[f];
    }
    int back() {
        if(size == 0) {
            cout << "Empty";
            return -1;
        }
        return arr[b-1];
    }
    int size() {
        return arr.size();
    }
    bool empty() {
        if(size == 0) return true;
        else false;
    }
    void display() {
        for(int i=f; i<b; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return ;
    }
};
int main() {
    queue q(0);
    cout << "Fill the queue sir : ";
    for(int i=1; i<=5; i++) {
        int c;
        cin>>c;
        q.push(c);
    }
    q.display();
    q.pop();
    q.pop();
    q.display();
}