// Linked List Implementation
// Singly Linked List (Insert, Delete, Traverse)

#include <iostream>
using namespace std;

class node
{
public:
  int val;
  node *next;

  node(int val)
  {
    this->val = val;
    this->next = NULL;
  }
};

class linkedList
{
public:
  node *head;
  node *tail;
  int size;
  linkedList()
  {
    head = NULL;
    tail = NULL;
    size = 0;
  }

  void insertAtHead(int value)
  {
    node *newNode = new node(value);

    if (size == 0)
    {
      head = tail = newNode;
    }
    else
    {
      newNode->next = head;
      head = newNode;
    }
    size++;
  }
  void insertAtTail(int value) {}
  void insertAtPosition(int value, int position) {}

  void deleteAtHead() {}
  void deleteAtTail() {}
  void deleteAtPosition(int position) {}

  void display() {
    node* temp = head;
    while(temp != nullptr) {
      cout << temp->val << " -> ";
      temp = temp->next;
    }
    cout << "NULL\n";
    }


  int getSize()
  {
    return size;
  }
  bool isEmpty()
  {
    return size == 0;
  }
  node *getHead()
  {
    return head;
  }
  node *getTail()
  {
    return tail;
  }
  void clear()
  {
    while (!isEmpty())
    {
      deleteAtHead();
    }
  }
  ~linkedList()
  {
    clear();
  }
};

int main()
{
  linkedList ll;
  ll.insertAtHead(2);
  ll.insertAtHead(1);
  
  ll.display();
}