# 📘 Linked List Interview Patterns (FAANG-Level)

---

## **1. Cycle Detection (Fast & Slow Pointer)**

Core idea: Use Floyd’s Cycle Detection algorithm (slow and fast pointers).

### 📌 Questions:

- [Linked List Cycle - LeetCode 141](https://leetcode.com/problems/linked-list-cycle/)
- [Linked List Cycle II - LeetCode 142](https://leetcode.com/problems/linked-list-cycle-ii/)
- [Detect Loop in Linked List - GFG](https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1)
- [Find the length of loop - GFG](https://practice.geeksforgeeks.org/problems/find-length-of-loop/1)

---

## **2. Reverse Linked List (Iterative & Recursive)**

Core idea: Change next pointers step by step.

### 📌 Questions:

- [Reverse Linked List - LeetCode 206](https://leetcode.com/problems/reverse-linked-list/)
- [Reverse a Linked List in groups of given size - GFG](https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1)
- [Reverse Linked List II - LeetCode 92](https://leetcode.com/problems/reverse-linked-list-ii/)
- [Palindrome Linked List - LeetCode 234](https://leetcode.com/problems/palindrome-linked-list/)

### 🧩 Template Code:

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;   // store next
        curr->next = prev;   // reverse link
        prev = curr;         // move prev
        curr = next;         // move curr
    }
    return prev;
}
```

---

## **3. Fast & Slow Pointer Tricks**

Core idea: Find middle, detect palindrome, cycle, etc.

### 📌 Questions:

- [Middle of the Linked List - LeetCode 876](https://leetcode.com/problems/middle-of-the-linked-list/)
- [Palindrome Linked List - LeetCode 234](https://leetcode.com/problems/palindrome-linked-list/)
- [Find the Start of Cycle - LeetCode 142](https://leetcode.com/problems/linked-list-cycle-ii/)
- [Remove Nth Node from End - LeetCode 19](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

### 🧩 Template Code:

```cpp
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // middle
}
```

---

## **4. Merge & Sort**

Core idea: Use dummy nodes + merge logic.

### 📌 Questions:

- [Merge Two Sorted Lists - LeetCode 21](https://leetcode.com/problems/merge-two-sorted-lists/)
- [Merge k Sorted Lists - LeetCode 23](https://leetcode.com/problems/merge-k-sorted-lists/)
- [Sort List - LeetCode 148](https://leetcode.com/problems/sort-list/)
- [Intersection Point in Y Shaped Linked Lists - GFG](https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1)

### 🧩 Template Code:

```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1) ? l1 : l2;
    return dummy.next;
}
```

---

## **5. Palindrome Check**

Core idea: Find middle → reverse second half → compare.

### 📌 Questions:

- [Palindrome Linked List - LeetCode 234](https://leetcode.com/problems/palindrome-linked-list/)
- [Check if Linked List is Palindrome - GFG](https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1)
- [Reorder List - LeetCode 143](https://leetcode.com/problems/reorder-list/)
- [Split Linked List in Parts - LeetCode 725](https://leetcode.com/problems/split-linked-list-in-parts/)

### 🧩 Template Code:

```cpp
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // Find middle
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    ListNode* prev = NULL, *curr = slow, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Compare halves
    ListNode* left = head, *right = prev;
    while (right) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }
    return true;
}
```

---

## **6. Add & Modify Numbers**

Core idea: Use carry management while traversing lists.

### 📌 Questions:

- [Add Two Numbers - LeetCode 2](https://leetcode.com/problems/add-two-numbers/)
- [Add Two Numbers II - LeetCode 445](https://leetcode.com/problems/add-two-numbers-ii/)
- [Multiply Two Linked Lists - GFG](https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1)
- [Subtraction in Linked List - GFG](https://practice.geeksforgeeks.org/problems/subtraction-in-linked-list/1)

### 🧩 Template Code:

```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }
        carry = sum / 10;
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
    }
    return dummy.next;
}
```

---

## **7. Intersection & Duplicate Removal**

Core idea: Use hashing or two-pointer tricks.

### 📌 Questions:

- [Intersection of Two Linked Lists - LeetCode 160](https://leetcode.com/problems/intersection-of-two-linked-lists/)
- [Remove Duplicates from Sorted List - LeetCode 83](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
- [Remove Duplicates from Sorted List II - LeetCode 82](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)
- [Remove duplicate element from sorted Linked List - GFG](https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1)

### 🧩 Template Code:

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA, *b = headB;
    while (a != b) {
        a = (a) ? a->next : headB;
        b = (b) ? b->next : headA;
    }
    return a;
}
```
