#include <bits/stdc++.h>
using namespace std;

class QueueArray {
  int *arr;
  int front, rear, size, capacity;

 public:
  QueueArray(int cap) {
    capacity = cap;
    arr = new int[capacity];
    front = 0;
    size = 0;
    rear = capacity - 1;
  }

  bool isFull() { return size == capacity; }
  bool isEmpty() { return size == 0; }

  void enqueue(int x) {
    if (isFull()) {
      cout << "Queue is full\n";
      return;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = x;
    size++;
  }

  void dequeue() {
    if (isEmpty()) {
      cout << "Queue is empty\n";
      return;
    }
    front = (front + 1) % capacity;
    size--;
  }

  int Front() {
    if (isEmpty()) return -1;
    return arr[front];
  }

  int Rear() {
    if (isEmpty()) return -1;
    return arr[rear];
  }
};

int main() {
  QueueArray q(5);
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  cout << q.Front() << " " << q.Rear() << "\n";
  q.dequeue();
  cout << q.Front() << " " << q.Rear() << "\n";
}
