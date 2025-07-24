#include<iostream>
using namespace std;
class node{
public:
    int val;
    node* next;
    node* prev;
    node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class DLL{
public:
    int size;
    node* head;
    node* tail;
    DLL() {
        head = tail = NULL;
        size = 0;
    }
    void insertAtTail(int val) {
        node* temp = new node(val);
        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }
    void deleteAtHead() {
        if(size == 0 ) {
            cout << "Invalid";
            return;
        }
        else {
            head = head->next;
            if(head) head->prev = NULL;
            if(head == NULL) tail = NULL;
            size--;
        }
    }
    void deleteAtTail() {
        if(size == 0 ) {
            cout << "Invalid";
            return;
        }
        else {
            node* temp = head;
            while(temp->next->next != NULL) temp = temp->next;
            temp->next = NULL;
            temp = tail;
            size--;
        }
    }
    void deleteAtIdx(int idx) {
        if(idx < 0 || idx > size) {
            cout << "Wrong input ";
            return ;
        }
        else if(idx == 0) deleteAtHead();
        else if(idx == size-1) deleteAtTail();
        else {
            node* temp = head;
            node* t = head;
            for(int i=0; i<idx-1; i++) temp = temp->next;
            for(int i=0; i<idx+1; i++) t = t->next;
            temp->next = t;
            t->prev = temp;
            size--;
        }
    }
    void display() {
        node* temp = head;
        cout << "Your List Sir : ";
        while(temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    DLL ll;
    for(int i=1; i<=7; i++) ll.insertAtTail(i*10);
    ll.display();
    ll.deleteAtHead();
    ll.display();
    ll.deleteAtTail();
    ll.display();
    ll.deleteAtIdx(3);
    ll.display();
}