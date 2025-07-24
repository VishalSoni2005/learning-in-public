#include<iostream>
using namespace std;
class node{
public:
    node* next;
    int val;

    node(int _val) {
        this->next = NULL;
        this->val = _val;
    }
};
class linkedList{ //Making insertHead, insertTail, insertIdx, display
public:
    int size;
    node* head;
    node* tail;
    linkedList() {
        size = 0;
        head = tail = NULL;
    }

    void insertTail(int val) {
        node* temp = new node(val);
        if(size == 0) head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
            size++;
        }
    }
    void display() {
        node* temp = head;
        while(temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
};
int main() {
    linkedList ll;
    for(int i=1; i<=10; i++) ll.insertTail(i*10);
    ll.display();
}