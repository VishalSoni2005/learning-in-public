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

    int getAtIdx(int idx) {
        if(idx == 0) return head->val;
        else if(idx == size-1) return tail->val;
        else {
            if(idx < size / 2) {
                node* temp = head;
                for(int i=0; i<idx; i++) temp = temp->next;
                return temp->val;
            }
                node* temp = tail;
                for(int i=1; i<=size-idx; i++)  temp = temp->prev;
                return temp->val;
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
    
}