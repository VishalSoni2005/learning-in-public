// LC->82
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    unordered_map<int, int> mp;
    ListNode *dum = new ListNode(INT_MAX), *ans = dum;

    ListNode* a = head;
    while (a) {
      mp[a->val]++;
      a = a->next;
    }

    while (head) {
      if (mp[head->val] == 1) {
        dum->next = head;
        dum = dum->next;
      }
      head = head->next;
    }
    dum->next = NULL;
    return ans->next;
  }
};