long long getNum(ListNode* head) {
  long long num = 0;
  while (head) {
    num = num * 10 + head->val;
    head = head->next;
  }
  return num;
}

ListNode* multiplyLists(ListNode* l1, ListNode* l2) {
  long long n1 = getNum(l1), n2 = getNum(l2);
  long long product = n1 * n2;
  if (product == 0) return new ListNode(0);

  ListNode* head = nullptr;
  while (product > 0) {
    ListNode* node = new ListNode(product % 10);
    node->next = head;
    head = node;
    product /= 10;
  }
  return head;
}
