#include <iostream>
using namespace std;

class Stack {
 private:
  int *arr;
  int capacity;
  int top;

  void resize() {
    int newCap = 2 * capacity;
    int *newArr = new int[newCap];

    for (int i = 0; i <= top; i++) {
      newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    capacity = newCap;
    cout << "Stack resized to capacity: " << capacity << endl;
  }

 public:
  Stack() {
    capacity = 4;  // starting with 4 capacity
    arr = new int[capacity];
    top = -1;
  }

  ~Stack() {
    delete[] arr;
  }

  void push(int x) {
    if (top + 1 == capacity) resize();
    top += 1;
    arr[top] = x;
  }

  void pop() {
    cout << "Element poped : " << arr[top--] << endl;
  }

  int size() {
    return top + 1;
  }
  int peek() {
    if (isEmpty()) {
      cout << "Stack is empty!" << endl;
      return -1;
    }
    return arr[top];
  }
  bool isEmpty() {
    return top == -1;
  }
};
