class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> us;
    while (headA) {
      us.insert(headA);
      headA = headA->next;
    }

    while (headB) {
      if (us.count(headB)) return headB;
      headB = headB->next;
    }

    return NULL;
  }
};