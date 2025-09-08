//! LC -> 725 important

class Solution {
 public:
  int findsize(struct ListNode* head) {
    ListNode* temp = head;
    int i = 0;
    while (temp) {
      i += 1;
      temp = temp->next;
    }
    return i;
  }

  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*> ans;
    int n = findsize(head);
    int size = n / k;
    int rem = n % k;
    ListNode* temp = head;

    while (temp) {
      ListNode* tempA = new ListNode(INT_MIN);
      ListNode* a = tempA;

      int s = size;
      if (rem > 0)
        s++;
      rem--;

      for (int i = 1; i <= s; i++) {
        tempA->next = temp;
        temp = temp->next;
        tempA = tempA->next;
      }

      tempA->next = NULL;
      ans.push_back(a->next);
    }

    if (ans.size() < k) {
      int rest = k - ans.size();
      for (int i = 0; i < rest; i++)
        ans.push_back(NULL);
    }

    return ans;
  }
};