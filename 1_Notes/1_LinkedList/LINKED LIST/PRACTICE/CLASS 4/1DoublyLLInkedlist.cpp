#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int val;
    node* next;
    node* prev; //EXTRA FOR DLL
    node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void printSingly(node* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void printRec(node* head) {
    if(head == NULL) return ;
    cout << head->val << " ";
    printRec(head->next);
}
void printRecRev(node* head){
    if(head == NULL) return ;
    printRecRev(head->next);
    cout << head->val << " ";
}
void printDoubly(node* tail) {
    while(tail) {
        cout << tail->val << " ";
        tail = tail->prev;
    }
    cout << endl;
}
int main() {
    
    node* a = new node(10);
    node* b = new node(20);
    node* c = new node(30);
    node* d = new node(40);
    node* e = new node(50);

    // SINGLE CONNECTION MADE
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    //DOUBLE CONNECTION MAKING
    e->prev = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;

    cout << "Straight order : " ; 
    printRec(a);
    cout << endl;

    cout << "Reversed order : ";
    printDoubly(e);


}