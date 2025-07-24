#include<iostream>
using namespace std;
class node{
public:
    int val;
    node* next;
    node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
int main() {
    node a(1);
    node b(2);
    node c(3);
    node d(4);

    a.next = &b;
    b.next = &c;
    c.next = &d;

    node temp = a;
    while(true) {
        cout << temp.val << " ";
        if(temp.next == NULL) break;
        temp = *(temp).next;
    }
}