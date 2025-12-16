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
class Solution {
 public:
  int lengthOfLoop(Node* head) {
    if (!head || !head->next) return 0;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect cycle
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        // Step 2: Count loop length
        int count = 1;
        Node* temp = slow->next;
        while (temp != slow) {
          count++;
          temp = temp->next;
        }
        return count;
      }
    }
    return 0;  // no cycle
  }
};
