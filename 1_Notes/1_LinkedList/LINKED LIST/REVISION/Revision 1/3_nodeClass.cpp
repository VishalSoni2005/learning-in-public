#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;         // WE ARE USING NODE POINTER TO POINT NEXT BECAUSE ANOTHER LIST IS ALSO A NODE SO ONE NODE STORE ADDRESS OF ANOTHER NODE
    Node(int val) {     
        this->val = val;
        this->next = NULL;
    }
};
int main() {
    Node a(1);
    Node b(2);
    Node c(4);
    Node d(8);
    //////////
    a.next = &b;
    b.next = &c;
    c.next = &d;
    ///////////
    cout << a.next->val;
}