class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *nxt = head;

    while (curr != nullptr)
    {
      nxt = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
    }
    return prev;
  }
};