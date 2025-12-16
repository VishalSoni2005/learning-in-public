/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* reverse(ListNode* head) {
    ListNode *nxt = head, *prev = NULL, *curr = head;

    while (nxt) {
      nxt = nxt->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
    }
    return prev;
  }

  bool isPalindrome(ListNode* head) {
    if (!head or !head->next) return 1;

    ListNode *slow = head, *fast = head;

    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // middle slow
    ListNode* middle = reverse(slow);
    fast = head;

    while (middle) {
      if (middle->val != fast->val) return 0;
      middle = middle->next;
      fast = fast->next;
    }

    return 1;
  }
};