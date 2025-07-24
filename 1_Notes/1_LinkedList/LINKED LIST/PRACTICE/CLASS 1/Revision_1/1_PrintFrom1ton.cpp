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

    void insertTail(int n) {
        node* temp = new node(n);
        if(size == 0) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
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
    int n;
    cout << "Enter number of terms : ";
    cin >> n;
    LinkedList ll;
    for(int i=1; i<=n; i++) ll.insertTail(i);
    cout << "First " << n << " natural numbers are -> ";
    ll.display();

}