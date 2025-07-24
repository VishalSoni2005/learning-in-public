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
    int size ;
    LinkedList() {
        head = tail = NULL;
        size = 0;
    }

    void insertAtTail(int val) {
        node* temp = new node(val);
        if(size == 0) head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    int getAtIdx(int idx) {
        if(idx<0 || idx>= size){
            cout << "Invalid Indx " ;
            return -1;
        }
        else if(idx==0) return head->val;
        else if(idx==size-1) return tail->val;
        else {
            node* temp = head;
            for(int i=0;i<idx;i++) temp = temp->next; //geting to the element at idx
            return temp->val;
        }
    }

    void deleteAtHead() {
        if(size == 0) {
            cout << "List is empty" ;
            return;
        }
        head = head->next;
        size--;
    }

    void deleteAtTail() {
        if(size == 0) {
            cout << "List is empty" ;
            return;
        }
        node* temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
        size--;
    }

    void deleteAtIdx(int idx){
        if(idx<0 || idx>size) cout << "INVALID INDEX" << endl;
        else if(idx == 0) deleteAtHead();
        else if(idx == size) deleteAtTail();
        else{
            node* temp1 = head;
            node* temp2 = temp1->next;
            for(int i=0; i<idx-1; i++) temp1 = temp1->next;
            for(int i=0; i<idx; i++) temp2 = temp2->next;
            temp1->next = temp2;
            size--;
        }
    }
    
    void display() {
        node* temp = head;
        while(temp != NULL) {
            cout << temp->val <<  " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList ll;
    for(int i=1; i<=5; i++) ll.insertAtTail(i);
    cout << "Before -> ";
    ll.display();
    ll.deleteAtIdx(2);
    cout << "After -> "; 
    ll.display();
    
    
}