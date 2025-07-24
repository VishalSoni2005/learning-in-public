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
class queue{
public:
    node* head;
    node* tail;
    int size;
    queue() {
        this->head = NULL;
        this->tail = NULL;
        size = 0;
    }

    void push(int x) {
        node* temp = new node(x);
        if(size == 0) {
            head = tail = temp;
            size++;
        }
        else{
            tail->next = temp;
            tail = temp;
            size++;
        }
    }

    void pop() {
        if(size == 0) {
            cout << "Queue is Empty: ";
            return ;
        }
        if(size == 1) {
            head = NULL;
            size--;
            return;
        }
        node* temp = head;
        head = temp->next;
        temp = head;
        size--;
    }
    int front() {
        return head->val;
    }
    void display() {
        if(size == 0) return ;
        node* temp = head;
        cout << "Your Queue Sir : ";
        while(temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
        return ;
    }
    int length() {
        return size;
    }
};
int main() {
    queue q;
    for(int i=1; i<=5; i++) {
        q.push(i * 10);
    }
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
}