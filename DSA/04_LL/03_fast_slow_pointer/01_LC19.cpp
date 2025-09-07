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
  int size(ListNode* head) {
    int list = 0;
    ListNode* temp = head;
    while (temp) {
      list++;
      temp = temp->next;
    }
    return list;
  }

  ListNode* removeNthFromEnd(ListNode* head, int k) {
    int n = size(head);

    if (k == n) {
      ListNode* todel = head->next;
      delete head;
      return todel;
    }

    int fromStart = n - k + 1;

    ListNode* temp = head;
    for (int i = 1; i < fromStart - 1; i++)
      temp = temp->next;

    ListNode* todel = temp->next;
    temp->next = temp->next->next;
    return head;
  }
};