#include<iostream>
using namespace std;
class Node{ //user defined data type
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
int main() {
    //Forming a sequence of 1,2,3,4
    Node a(1);
    Node b(2);
    Node c(3);
    Node d(4);
    //FORMING LL
    a.next = &b;
    b.next = &c;
    c.next = &d;

    cout << a.val << endl;
    a.next->val = 90;
    //print value of b usng a only
    cout << a.next->val << endl;
    cout << b.next->val << endl;
}