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
int size(node* head) {
    int size = 0;
    node* temp = head;
    while(temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}
void recLL(node* head) {
    if(head == NULL) return ;
    cout << head->val << " ";
    recLL(head->next);
}
void display(node* head) {
    node* temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    node* a = new node(1);
    node* b = new node(2);  //WHY DYNAMIC ALLOCATION >
    node* c = new node(3);  //ANS-> ONLY FOR EASY OF TRAVERSING LINKEDlIST
    node* d = new node(4);
    a->next = b;
    b->next = c;
    c->next = d;

    // node* temp = a;
    // while(temp != NULL) {
    //     cout << temp->val << " ";
    //     temp = temp->next;
    // }
    cout << "Your formed LinkedList is : ";
    display(a);
    cout << "Size of linkedList is : "<< size(a) << endl;
    cout << "Recursive Display : " ;
    recLL(a);
    cout << endl;
    
}