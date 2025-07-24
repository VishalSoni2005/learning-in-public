#include<iostream>
using namespace std;
class node{
public:
    int val;
    node* next;
    node(int val) {
        this->val = val;
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
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
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
    cout << "Your list before head Addition : " ;
    ll.display();
    int p;
    cout << "Enter the number you wanna insert at head : ";
    cin >> p;
    ll.insertAtHead(p);
    cout << "After Insertion => ";
    ll.display() ;
}