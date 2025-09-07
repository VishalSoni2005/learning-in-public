/*
class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

//* this follow a special method

class Solution {
 public:
  int cycleStart(Node* head) {
    // code here
    if (!head || !head->next) return NULL;

    Node *slow = head, *fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) break;
    }

    if (!fast || !fast->next) return -1;

    fast = head;  // todo: IT WORKS
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow->data;
  }
};