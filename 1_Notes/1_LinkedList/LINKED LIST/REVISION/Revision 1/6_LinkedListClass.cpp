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
class linkedList{
public:
    node* head;
    node* tail;
    int size;
    linkedList() {
        tail = head = NULL;
        size = 0;
    }

    // Insertion
    void insertAtEnd(int val) {
        node* temp = new node(val); // First we are assigning new node to temp
        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insertAtBegin(int val) {
        node*temp = new node(val);
        if(size == 0) head = tail = temp;
        else{
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertAtidx(int val, int idx) {
        if(idx == 0) insertAtBegin(val);
        else if (idx == size) insertAtEnd(val);
        else if(idx < 0 || idx > size) cout << "Wrong Sir " << endl;
        else {
            node* temp = head;
            node* t = new node(val);
            int i = 1;
            while(i < idx) {
                temp = temp->next;
                i++;
            }
            t->next = temp->next;
            temp->next = t;
        }
        size++;
    }

    int getAtIdx(int idx) {     // INDEXING IS STARTING FORM 1
        node* temp = head;
        int i = 1;
        while(i <= idx - 1) {
            temp = temp->next;
            i++;
        }
        return temp->val;
    }

    void deleteAtHead() {
        if(size == 0) cout << "Wrong Sir" << endl;
        else {
            if(size == 1) head = tail = NULL;
            else{
                node* temp = head;
                temp = temp->next;
                head = temp;
            }
            size--;
        }
    }

    void deleteAtTail() {
        if(size == 0) cout << "Wrong Sir" << endl;
        else{
            if(size == 1) head = tail = NULL;
            else{
                node* temp = head;
                while(temp->next->next != NULL) {temp = temp->next;}
                    temp->next = NULL;
                    size--;
            }
        }
    }

    void deleteAtIdx(int idx) {
        node* temp = head;
        int i = 1;
        while(i <= idx - 2) {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
        size--;
    }

    void display() {
        node* temp = head;
        while(temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
};
int main() {
    linkedList ll;
    cout << "Your LinkedList sir -> ";
    for(int i=1; i<=10; i++) {
        ll.insertAtEnd(i);
    }
    ll.display();
    // ll.insertAtBegin(0);
    // ll.display();

    // // ll.insertAtidx(69,3);
    // // ll.display();
    // // ll.insertAtBegin(0);
    // // ll.display();
    // ll.insertAtEnd(11);
    // ll.display();

    // ll.insertAtidx(12, 11);
    // ll.display();

    // cout << ll.getAtIdx(1) << endl;
    // cout << ll.getAtIdx(5) << endl;

    ll.deleteAtHead();
    cout << "Modified 1 LinkedList Sir -> ";
    ll.display();
    ll.deleteAtTail();
    cout << "Modified 2 LinkedList Sir -> ";
    ll.display();
    ll.deleteAtIdx(3);
    cout << "Modified 3 LinkedList Sir -> ";
    ll.display();
}   