//Q DELETE THE NODE GIVEN IT IS NOT THE FIRST OR LAST
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
    node* size;
    LinkedList() {
        head = tail = NULL;
        size = 0;
    }
    

    void insertBack(int val) {
        node* temp = new node(val);
        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void deleteTar(int tar) {
        node* temp = head;
        while(temp->val == tar) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return;
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
    cout << "Enter size of your linkedList : ";
    cin>> n;
    LinkedList ll;
    cout << "Fill your LInkedlist using space : ";
    for(int i=0; i<n; i++) {
        int m ;
        cin >> m;
        ll.insertBack(m);
    }
    cout << "Your linkedlist before deletion : ";
    ll.display();
    int p;
    cout << "Enter the value you wanna delete : ";
    cin>> p;
    ll.deleteTar(p);
    cout << "Your linkedList after Deletion : ";
    ll.display();



}