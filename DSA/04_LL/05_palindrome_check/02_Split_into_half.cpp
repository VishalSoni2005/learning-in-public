//* gfg
class Solution {
 public:
  pair<Node*, Node*> splitList(struct Node* head) {
    // code here
    Node* fast = head;
    Node* slow = head;

    while (fast->next != head && fast->next->next != head) {
      fast = fast->next->next;
      slow = slow->next;
    }

    if (fast->next->next == head) fast = fast->next;

    Node* head1 = head;

    Node* head2 = slow->next;
    slow->next = head;
    fast->next = head2;

    return {head1, head2};
  }
};