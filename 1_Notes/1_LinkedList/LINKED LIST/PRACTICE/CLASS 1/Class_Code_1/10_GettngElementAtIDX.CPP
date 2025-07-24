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
    int n;
    cout << "Enter the size of node : " ;
    cin >>n;
    LinkedList ll;
    for(int i=1; i<=n; i++) ll.insertAtTail(i);
    cout << "LInked list  : ";
    ll.display();
    cout << ll.getAtIdx(2);
    
}