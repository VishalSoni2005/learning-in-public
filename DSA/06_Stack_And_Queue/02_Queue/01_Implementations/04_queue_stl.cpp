//* Basic Operations :
//   enqueue(x) / push(x) → Insert element at rear.
//   dequeue() /pop() → Remove element from front.
//   front() → Get the first element.
//   rear() → Get the last element.
//   isEmpty() → Check if queue is empty.
//   size() → Number of elements in queue.

#include <bits/stdc++.h>
using namespace std;

int main() {
  queue<int> q;

  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  cout << q.back() << '\n';

  q.pop();
  // q.pop()
  cout << q.front() << '\n';

  cout << q.size() << endl;
  return 0;
}