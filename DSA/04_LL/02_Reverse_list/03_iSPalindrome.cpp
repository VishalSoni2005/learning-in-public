class Solution {
 public:
  ListNode* reversed_list(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* nxt = head;

    while (curr != nullptr) {
      nxt = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
    }
    return prev;
  }

  bool isPalindrome(ListNode* head) {
    if (!head or !head->next)
      return true;

    //? KEY IS FIND MIDLE REVERSE FROM MIDDLE TO END AND THEN COMPARE SEQUENTIALLY

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast and fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    // middle -> slow
    ListNode* reversePart = reversed_list(slow);

    fast = head;
    while (reversePart) {
      if (reversePart->val != fast->val) return 0;
      fast = fast->next;
      reversePart = reversePart->next;
    }

    return 1;
  }
};