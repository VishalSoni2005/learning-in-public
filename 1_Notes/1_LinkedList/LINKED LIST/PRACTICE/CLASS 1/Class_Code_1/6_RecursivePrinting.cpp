#include <iostream>
using namespace std;
class node{
public:
    int value;
    node *next;
    node(int value) {
        this->value = value;
        this->next = NULL;
    }
};

void recPrint(node* head) {
    if(head == NULL) return;
    cout << head->value << " ";
    recPrint(head->next);
}
int main() {
    node* a = new node(1);
    node* b = new node(2);
    node* c = new node(3);
    node* d = new node(4);
    a->next = b;
    b->next = c;
    c->next = d;
    
    recPrint(a);
}