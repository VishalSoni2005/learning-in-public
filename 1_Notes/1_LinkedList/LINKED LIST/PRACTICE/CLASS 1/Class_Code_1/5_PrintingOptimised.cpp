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
    Node* a = new Node(100); // by default this node contain 100 , and null address
    Node* b = new Node(200);
    Node* c = new Node(300);
    Node* d = new Node(400);
    a->next = b;
    b->next = c;
    c->next = d;

    Node* temp = a;
    while(temp != NULL) {
        cout << temp->val << endl;
        temp = temp->next;
    }


}