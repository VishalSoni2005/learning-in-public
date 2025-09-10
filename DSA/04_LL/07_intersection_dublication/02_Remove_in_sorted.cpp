
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head or !head->next) return head;

    ListNode* temp = head;
    while (temp->next) {
      if (temp->val == temp->next->val)
        temp->next = temp->next->next;
      else
        temp = temp->next;
    }
    return head;
  }
};