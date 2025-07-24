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
class deque{
public:
    int size;
    node* head;
    node* tail;
    deque() {
        size = 0;
        head = tail = NULL;
    }

    
    void push_back(int val) {
        node* temp = new node(val);
        if(size == 0) {
            head = tail = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void push_front(int val) {
        node* temp = new node(val);
        if(size == 0) head = tail = temp;
        else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }
    void pop_front() {
        if(size == 1) {
            head = tail = NULL;
            cout << "Now your deque is empty " << endl;
            return ;
        }
        else{
            head = head->next;
            head->prev = NULL;
        }
        size--;
    }
    void pop_back() {
        if(size == 1) {
            head = tail = NULL;
            cout << "Now you deque is empty " << endl;
            return ;
        }
        else {
            tail = tail->prev;
            tail->next = NULL;
        }
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
    int size_deque( ){
        return size;
    }
    int front(){
        return head->val;
    }
    int back() {
        return tail->val;
    }

};
int main() {
    int n;
    cout << "Enter size : ";
    cin >> n;
    deque it;
    for(int i=1; i<=n; i++) it.push_back(i * 10);
    it.display();
    cout << it.front() << endl;
    cout << it.back() << endl;
    
}