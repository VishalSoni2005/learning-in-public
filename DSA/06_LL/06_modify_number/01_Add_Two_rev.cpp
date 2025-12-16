
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *curr = new ListNode(INT_MIN), *ans = curr;
    int carry = 0;

    while (l1 or l2 or carry) {
      int sum = carry;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }

      int digit = sum % 10;
      carry = sum / 10;

      curr->next = new ListNode(digit);
      curr = curr->next;
    }

    return ans->next;
  }
};