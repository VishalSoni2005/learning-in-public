#include <iostream>
using namespace std;

// Node structure
class Node {
 public:
  int data;
  Node* next;

  Node(int value) {
    data = value;
    next = NULL;
  }
};

class Stack {
 private:
  Node* top;  // pointer to top node

 public:
  // Constructor
  Stack() {
    top = NULL;
  }

  // Push element onto stack
  void push(int x) {
    //! not top is always at first node of ll
    Node* newNode = new Node(x);
    newNode->next = top;  // link new node to previous top
    top = newNode;
    cout << "Pushed: " << x << endl;
  }

  // Pop element from stack
  void pop() {
    if (isEmpty()) {
      cout << "Stack Underflow! Nothing to pop." << endl;
      return;
    }
    cout << "Popped: " << top->data << endl;
    Node* temp = top;
    top = top->next;
    delete temp;
  }

  // Peek top element
  int peek() {
    if (isEmpty()) {
      cout << "Stack is empty!" << endl;
      return -1;
    }
    return top->data;
  }

  // Check if stack is empty
  bool isEmpty() {
    return top == NULL;
  }

  // Display stack elements
  void display() {
    if (isEmpty()) {
      cout << "Stack is empty!" << endl;
      return;
    }
    cout << "Stack elements: ";
    Node* curr = top;
    while (curr != NULL) {
      cout << curr->data << " ";
      curr = curr->next;
    }
    cout << endl;
  }
};

// Driver code
int main() {
  Stack s;

  s.push(10);
  s.push(20);
  s.push(30);
  s.display();

  cout << "Top element: " << s.peek() << endl;

  s.pop();
  s.display();

  return 0;
}
