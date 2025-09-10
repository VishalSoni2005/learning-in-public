/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  Node* removeZeros(Node* head) {
    while (head and head->data == 0 and head->next) head = head->next;
    return head;
  }

 public:
  Node* addTwoLists(Node* head1, Node* head2) {
    Node* l1 = removeZeros(head1);
    Node* l2 = removeZeros(head2);

    if (!l1 and !l2) return new Node(0);
    if (!l2) return l1;
    if (!l1) return l2;

    stack<int> s1, s2;

    while (l1) {
      s1.push(l1->data);
      l1 = l1->next;
    }

    while (l2) {
      s2.push(l2->data);
      l2 = l2->next;
    }

    Node* head = NULL;
    int carry = 0;

    while (!s1.empty() or !s2.empty() or carry) {
      // stack is prepared
      int sum = carry;
      if (!s1.empty()) {
        sum += s1.top();
        s1.pop();
      }

      if (!s2.empty()) {
        sum += s2.top();
        s2.pop();
      }

      carry = sum / 10;

      Node* temp = new Node(sum % 10);
      temp->next = head;
      head = temp;
    }
    return head;
  }
};