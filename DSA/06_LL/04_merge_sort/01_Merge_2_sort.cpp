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
  ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    if (a == nullptr or b == nullptr) {  // base case
      return a ? a : b;
    }
    if (a->val > b->val) {
      swap(a, b);  // ensuring "a" always have smaller value
    }
    a->next = mergeTwoLists(a->next, b);
    return a;

    // ListNode* tail = new ListNode(INT_MIN);
    // ListNode* dummy = tail;

    // while (a and b) {
    //   if (a->val > b->val) {
    //     tail->next = b;
    //     b = b->next;
    //   } else {
    //     tail->next = a;
    //     a = a->next;
    //   }
    //   tail = tail->next;
    // }
    // // jo bacha usko dal to
    // tail->next = (a) ? a : b;
    // return dummy->next;
  }
};