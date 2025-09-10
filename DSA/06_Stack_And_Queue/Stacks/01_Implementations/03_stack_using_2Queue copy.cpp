// Using 2 Queues
//     Push is O(1),
//     Pop is O(n).

#include <iostream>
#include <queue>
using namespace std;

class Stack {
 private:
  queue<int> q1, q2;

 public:
  //* Push element onto stack
  //! remember the steps
  void push(int x) {
    // Step 1: Push new element into q2
    q2.push(x);

    // Step 2: Move all elements from q1 → q2
    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }

    // Step 3: Swap q1 and q2
    swap(q1, q2);

    cout << "Pushed: " << x << endl;
  }

  // Pop element from stack
  void pop() {
    if (q1.empty()) {
      cout << "Stack Underflow! Nothing to pop." << endl;
      return;
    }
    cout << "Popped: " << q1.front() << endl;
    q1.pop();
  }

  // Peek top element
  int peek() {
    if (q1.empty()) {
      cout << "Stack is empty!" << endl;
      return -1;
    }
    return q1.front();
  }

  // Check if stack is empty
  bool isEmpty() {
    return q1.empty();
  }

  // Display stack (top to bottom)
  void display() {
    if (q1.empty()) {
      cout << "Stack is empty!" << endl;
      return;
    }

    cout << "Stack elements (top to bottom): ";
    queue<int> temp = q1;  // copy to preserve order
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
