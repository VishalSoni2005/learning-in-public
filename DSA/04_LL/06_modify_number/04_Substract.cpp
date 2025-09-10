class Solution {
  int size(Node* head) {
    int len = 0;
    while (head) {
      len++;
      head = head->next;
    }
    return len;
  }

  Node* removeLeadingZeros(Node* head) {
    while (head && head->data == 0 && head->next) {
      head = head->next;
    }
    return head;
  }

  Node* reverse(Node* head) {
    Node* prev = NULL;
    while (head) {
      Node* nxt = head->next;
      head->next = prev;
      prev = head;
      head = nxt;
    }
    return prev;
  }

  // Compare two lists of same length
  bool isSmaller(Node* l1, Node* l2) {
    while (l1 && l2) {
      if (l1->data < l2->data) return true;
      if (l1->data > l2->data) return false;
      l1 = l1->next;
      l2 = l2->next;
    }
    return false;  // equal means not smaller
  }

 public:
  Node* subLinkedList(Node* head1, Node* head2) {
    head1 = removeLeadingZeros(head1);
    head2 = removeLeadingZeros(head2);

    int n1 = size(head1), n2 = size(head2);

    // Ensure head1 >= head2
    if (n1 < n2 || (n1 == n2 && isSmaller(head1, head2))) {
      swap(head1, head2);
    }

    // Reverse both lists
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node* result = NULL;
    Node* tail = NULL;
    int borrow = 0;

    while (head1 || head2) {
      int d1 = head1 ? head1->data : 0;
      int d2 = head2 ? head2->data : 0;

      int diff = d1 - borrow - d2;

      if (diff < 0) {
        diff += 10;
        borrow = 1;
      } else {
        borrow = 0;
      }

      Node* node = new Node(diff);
      if (!result) {
        result = node;
        tail = node;
      } else {
        tail->next = node;
        tail = node;
      }

      if (head1) head1 = head1->next;
      if (head2) head2 = head2->next;
    }

    // Reverse result back
    result = reverse(result);

    // Remove leading zeros
    result = removeLeadingZeros(result);

    return result ? result : new Node(0);
  }
};
