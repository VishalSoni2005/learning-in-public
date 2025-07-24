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

    void insertAtTail(int val) {   //insert a node at last
        node* temp = new node(val);
        if(size == 0) head = tail = temp;
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp; 
        }
        size++;
    }

    void insertAtHead(int val) {
        node* temp = new node(val);
        if(size == 0) head = tail = temp;
        else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void insertAtIdx(int val, int idx) {    //considering indexing from zero
        if(idx == size || idx > size) {
             cout << "Wrong Input"<< endl;
             return;
        }
        else if(idx == size-1) insertAtTail(val);
        else if(idx == 0) insertAtHead(0);
        else {
            node* temp = new node(val);
            node* t = head;
            for(int i=0; i<idx-1; i++) t = t->next;
            temp->next = t->next;
            t->next = temp;
            temp->prev = t;
            temp->next->prev = temp;
            size++;
        }
    }

    void display() {
        node* temp = head;
        while(temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    DLL ll;
    cout << "Your LinkedList Sir -> ";
    for(int i=1; i<6; i++) {
        ll.insertAtTail(i*10);
    }
    ll.display();

    // ll.insertAtHead(0);
    // ll.display();

    ll.insertAtIdx(35,3);
    ll.display();

}