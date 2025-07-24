#include<bits/stdc++.h>
using namespace std;
class node{ // USER DEFINED DATA TYPE
public:
    int value;
    node *next;
    node(int value) {
        this->value = value;
        this->next = NULL;
    }
};
class LinkedList{
public:
    node* head;
    node* tail;
    int size;
    LinkedList() {
        tail = head = NULL;
        size = 0;
    }

    void insertAtEnd(int val) {
        node* temp = new node(val);
        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void display() {
        node* temp = head;
        while(temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList ll ;
    int n;
    cout << "Enter number of terms -> ";
    cin >> n;
    for(int i=1; i<=n; i++) {
        ll.insertAtEnd(i);
    }
    cout << "There we go -> "; 
    ll.display();
    cout << "Size of linkedList is -> " << ll.size << endl;
    cout << "Enter the element you wanna to insert -> " ;
    int p;
    cin >> p;
    ll.insertAtEnd(p);

    cout << "After addition => ";
    ll.display();
    cout << "After additon size is --> " << ll.size;
    
}
