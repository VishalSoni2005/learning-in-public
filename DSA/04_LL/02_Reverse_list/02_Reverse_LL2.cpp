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
 //! brute force solution using two pass and array
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    // for brute force solution intutuio of making an vector
    if (!head or !head->next) return head;
    if (left == right) return head;

    vector<int> data;
    ListNode* temp = head;
    int count = 1;

    while (temp) {
      if (count >= left and count <= right) data.push_back(temp->val);
      temp = temp->next;
      count++;
    }
    reverse(data.begin(), data.end());

    temp = head;
    count = 1;
    int idx = 0;
    while (temp) {
      if (count >= left and count <= right) temp->val = data[idx++];
      temp = temp->next;
      count++;
    }

    return head;
  }
};

//todo: Optimised solution

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    // for brute force solution intutuio of making an vector
    if (!head || left == right) return head;

    // Dummy node simplifies edge cases (like reversing from head)
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    // Step 1: Move prev to node before `left`
    for (int i = 1; i < left; i++) {
      prev = prev->next;
    }

    // Step 2: Reverse sublist
    ListNode* curr = prev->next;
    ListNode* nxt = NULL;
    ListNode* last = curr;

    ListNode* revPrev = NULL;
    for (int i = 0; i <= right - left; i++) {
      nxt = curr->next;
      curr->next = revPrev;
      revPrev = curr;
      curr = nxt;
    }

    // Step 3: Reconnect
    prev->next = revPrev;  // connect before left
    last->next = curr;     // connect after right

    return dummy.next;
  }
};
