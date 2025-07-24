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
class stack{
public:
    int size;
    node* head;
    stack() {
        this->head = NULL;
        size = 0;
    }

    void push(int val) {
        node* temp = new node(val);
        temp->next = head;
        head = temp;
        size++;
    }
    

    void pop() {
        if(size > 0) {
        head = head->next;
        size--;
        }
        else {
            cout << "Stack underflow" << endl;
        }
    }

    int top() {
        return head->val;
    }

    void displayRec(node* temp) {
        if(temp == NULL) return ;
        displayRec(temp->next);
        cout << temp->val << " ";
    } 
    void display() {
        node* temp = head;
        displayRec(temp);
        cout << endl;
    }
}; 
int main() {
    stack st;
 
    for(int i=1; i<=5; i++) st.push(i*10);
    cout << "Your Original Stack Sir -> ";
    st.display();
}