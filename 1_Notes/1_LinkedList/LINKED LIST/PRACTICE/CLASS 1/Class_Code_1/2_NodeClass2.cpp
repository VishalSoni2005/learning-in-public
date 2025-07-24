#include<iostream>
using namespace std;
class Node{
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

    // Q ASCESS VALUE OF 'd' USING 'a' ONLY
    cout << a.next->next->next->val << endl; // line 25 and 26 are one and same thing
    cout <<(*(*((*(a.next)).next)).next).val << endl;

}