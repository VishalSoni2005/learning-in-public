// Using 1 Queues
//     Push is O(n),
//     Pop is O(1).

#include <iostream>
#include <queue>
using namespace std;

class Stack {
 private:
  queue<int> q;

 public:
  // Push element into stack
  void push(int x) {
    int n = q.size();
    q.push(x);

    // Rotate the queue to move new element to front
    for (int i = 0; i < n; i++) {
      q.push(q.front());
      q.pop();
    }
  }

  // Pop element from stack
  void pop() {
    if (q.empty()) {
      cout << "Stack Underflow! Nothing to pop." << endl;
      return;
    }
    cout << "Popped: " << q.front() << endl;
    q.pop();
  }

  // Peek top element
  int peek() {
    if (q.empty()) {
      cout << "Stack is empty!" << endl;
      return -1;
    }
    return q.front();
  }

  // Check if stack is empty
  bool isEmpty() {
    return q.empty();
  }

  // Display elements (top to bottom)
  void display() {
    if (q.empty()) {
      cout << "Stack is empty!" << endl;
      return;
    }

    cout << "Stack elements (top to bottom): ";
    queue<int> temp = q;  // copy to preserve original
    while (!temp.empty()) {
      cout << temp.front() << " ";
      temp.pop();
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
