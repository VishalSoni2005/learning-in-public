#include<iostream>
using namespace std;
class node{
public:
    int val;
    node* next;
    node(int _val) : val(_val), next(NULL){};
};
class LinkedList{
public:
    node* head; 
    node* tail;
    int size;
    LinkedList() : head(NULL), tail(NULL), size(0){}

    void insertTail(int val) {
        node* temp = new node(val);
        if(size == 0 ) head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    int getIdx(int idx) {
        if(idx == 0) {
            cout << "indexing have done form one ";
            return -1;
        }
        else if(idx < 0 || idx > size) {
            cout << "chutiya ";
            return -1;
        }
        else if(idx == size) {
            node* temp = head;
            for(int i=1; i<size; i++) temp = temp->next;
            return temp->val;
        }
        else{
            node* temp = head;
            for(int i=1; i<idx; i++) temp = temp->next;
            return temp->val;
        }
        
    }

    void deleteIdx(int idx) {
        node* temp = head;
        for(int i=1; i<idx-1; i++) temp = temp->next;
        temp->next = temp->next->next;
        size--;
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
    LinkedList m;
    for(int i=1; i<11; i++) m.insertTail(i);
    m.display();
// cout << m.getIdx(5) << endl;
    m.deleteIdx(3);
    m.display();
    
}
