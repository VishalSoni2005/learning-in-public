#include<iostream>
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
void display(node *head) {
    node *temp = head;
    while(temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
int size(node *head) {
    int count = 0;
    node *temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int main() {
    node *a = new node(11);
    node *b = new node(22);
    node *c = new node(33);
    node *d = new node(44);
    a->next = b;
    b->next = c;
    c->next = d;

    display(a);
    cout << "Number of members are : " << size(a);
}