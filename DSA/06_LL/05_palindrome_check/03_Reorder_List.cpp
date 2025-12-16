// Your overall algorithm is perfect :
//     Find middle with slow / fast ✅
//     Reverse second half ✅
//     Merge alternately ✅
//! important
class Solution {
 public:
  ListNode* reverse(ListNode* head) {
    ListNode *curr = head, *nxt = head, *prev = NULL;

    while (nxt) {
      nxt = nxt->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
    }
    return prev;
  }

  void reorderList(ListNode* head) {
    if (!head->next)
      return;
    // algo i follow:
    // find middle
    // reverse form middle
    // temp = head;
    // while temp;

    ListNode* fast = head;
    ListNode* slow = head;

    while (fast and fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    ListNode* head2 = reverse(slow->next);
    slow->next = NULL;

    ListNode* l1 = head;
    ListNode* l2 = head2;

    while (l2) {
      ListNode* n1 = l1->next;
      ListNode* n2 = l2->next;

      l1->next = l2;
      l2->next = n1;

      l1 = n1;
      l2 = n2;
    }

    return;
  }
};