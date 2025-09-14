#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

class LinkedListQueue {
  Node* front;
  Node* rear;

 public:
  LinkedListQueue() {
    front = rear = nullptr;
  }

  // Enqueue (insert at rear)
  void enqueue(int x) {
    Node* newNode = new Node(x);
    if (rear == nullptr) {  // empty queue
      front = rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
  }

  // Dequeue (remove from front)
  int dequeue() {
    if (front == nullptr) {
      cout << "Queue is empty\n";
      return -1;
    }
    Node* temp = front;
    int val = temp->data;
    front = front->next;

    if (front == nullptr) rear = nullptr;  // queue became empty
    delete temp;
    return val;
  }

  // Peek front
  int Front() {
    if (front == nullptr) return -1;
    return front->data;
  }

  // Peek rear
  int Rear() {
    if (rear == nullptr) return -1;
    return rear->data;
  }

  // Check empty
  bool isEmpty() {
    return front == nullptr;
  }
};

int main() {
  LinkedListQueue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  cout << q.dequeue() << "\n";  // 10
  cout << q.Front() << "\n";    // 20
  cout << q.Rear() << "\n";     // 30

  q.enqueue(40);
  cout << q.dequeue() << "\n";  // 20
  cout << q.dequeue() << "\n";  // 30
  cout << q.dequeue() << "\n";  // 40
  cout << q.dequeue() << "\n";  // empty → -1
}
