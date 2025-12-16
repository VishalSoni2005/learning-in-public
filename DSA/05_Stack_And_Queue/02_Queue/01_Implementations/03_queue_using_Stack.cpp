#include <bits/stdc++.h>
using namespace std;

class AmortizedQueue {
  stack<int> s1, s2;

  void transferIfNeeded() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
  }

 public:
  void enqueue(int x) {
    s1.push(x);  // always O(1)
  }

  int dequeue() {
    transferIfNeeded();
    if (s2.empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    int val = s2.top();
    s2.pop();
    return val;
  }

  int Front() {
    transferIfNeeded();
    if (s2.empty()) return -1;
    return s2.top();
  }

  bool isEmpty() {
    return s1.empty() && s2.empty();
  }
};

int main() {
  AmortizedQueue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  cout << q.dequeue() << "\n";  // 10
  cout << q.Front() << "\n";    // 20
  q.enqueue(40);
  cout << q.dequeue() << "\n";  // 20
  cout << q.dequeue() << "\n";  // 30
  cout << q.dequeue() << "\n";  // 40
  cout << q.dequeue() << "\n";  // empty → -1
}
