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

    void insertAtMiddle(int val, int idx) {
        if(idx<0 || idx>size) cout << "INVALID INDEX" << endl;
        else if(idx == 0) insertAtHead(val);
        else if(idx == size) insertAtTail(val);
        else{
            node* t = new node(val);
            node* temp = head;
            for(int i=1; i<idx; i++) { // reaching to the index
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
            
        }
    }

    void insertAtHead(int _val) {
        node* temp = new node(_val);
        if(size == 0) head = tail = temp;
        else {
            temp->next = head;
            head = temp;
        }
        size++;
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