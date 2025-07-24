#include<iostream>
using namespace std;
class node{
public:
    int value;
    node* next;
    node(int val) {
        this->value = val;
        next = NULL;
    }
};
class LinkedList{
public:
    node* head;
    node* tail; 
    int size;
    LinkedList() {
        head = tail = NULL;
        size = 0;
    }
    void insertAtTail(int value) {
        node* temp = new node(value);
        if(size == 0) head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    } 

    void insertAtHead(int value) {
        node* temp = new node(value);
        if(size == 0) head = tail = temp;
        else{
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insertAtMiddle(int value, int idx) {
        if(idx < 0 || idx > size) cout << "Error" << endl;
        else if(idx==0) insertAtHead(value);
        else if(idx == size) insertAtTail(value);
        else {
            node* temp = head;
            node* t = new node(value);
            for(int i=1; i<idx; i++) temp = temp->next;
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }
    void display() {
        node* temp = head;
        while(temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the size of node : " ;
    cin >>n;
    LinkedList ll;
    for(int i=1; i<=n; i++) ll.insertAtTail(i);
    cout << "LInked list before insertion : ";
    ll.display();
    cout << "After Insertion => ";
    ll.insertAtMiddle(89, 4);
    ll.display() ;
}