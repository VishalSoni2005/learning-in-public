// topic covered in this file: 
// 1: creating a node class
// 2: creating a linked list class
// 3: insert at start, end and middle
// 4: delete at start, end and middle
// 5: traverse the linked list
// 6: search for an element in the linked list
// 7: reverse the linked list
// 8: find the length of the linked list

import java.util.*;
import java.io.*;
import java.lang.*;
import java.util.function.*;
import java.linkedlist.*;

public class syntax {

    // 1. Node class
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    // 2. Linked List class
    static class LinkedList {
        ListNode head;

        // 3. Insert at start
        void insertAtStart(int val) {
            ListNode newNode = new ListNode(val);
            newNode.next = head;
            head = newNode;
        }

        // Insert at end
        void insertAtEnd(int val) {
            ListNode newNode = new ListNode(val);

            if (head == null) {
                head = newNode;
                return;
            }

            ListNode temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }

            temp.next = newNode;
        }

        // Insert at position (0-based index)
        void insertAtPosition(int index, int val) {
            if (index == 0) {
                insertAtStart(val);
                return;
            }

            ListNode newNode = new ListNode(val);
            ListNode temp = head;

            for (int i = 0; i < index - 1 && temp != null; i++) {
                temp = temp.next;
            }

            if (temp == null) return;

            newNode.next = temp.next;
            temp.next = newNode;
        }

        // 4. Delete at start
        void deleteAtStart() {
            if (head == null) return;
            head = head.next;
        }

        // Delete at end
        void deleteAtEnd() {
            if (head == null) return;

            if (head.next == null) {
                head = null;
                return;
            }

            ListNode temp = head;
            while (temp.next.next != null) {
                temp = temp.next;
            }

            temp.next = null;
        }

        // Delete at position
        void deleteAtPosition(int index) {
            if (head == null) return;

            if (index == 0) {
                deleteAtStart();
                return;
            }

            ListNode temp = head;

            for (int i = 0; i < index - 1 && temp.next != null; i++) {
                temp = temp.next;
            }

            if (temp.next == null) return;

            temp.next = temp.next.next;
        }

        // 5. Traverse
        void traverse() {
            ListNode temp = head;
            while (temp != null) {
                System.out.print(temp.val + " -> ");
                temp = temp.next;
            }
            System.out.println("null");
        }

        // 6. Search
        boolean search(int key) {
            ListNode temp = head;

            while (temp != null) {
                if (temp.val == key) return true;
                temp = temp.next;
            }

            return false;
        }

        // 7. Reverse
        void reverse() {
            ListNode prev = null;
            ListNode curr = head;

            while (curr != null) {
                ListNode next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
            }

            head = prev;
        }

        // 8. Length
        int length() {
            int count = 0;
            ListNode temp = head;

            while (temp != null) {
                count++;
                temp = temp.next;
            }

            return count;
        }
    }

    // Main function to test everything
    public static void main(String[] args)  {
        LinkedList list = new LinkedList();

        // Insert operations
        list.insertAtStart(10);
        list.insertAtStart(5);
        list.insertAtEnd(20);
        list.insertAtEnd(30);
        list.insertAtPosition(2, 15);

        System.out.println("After Insertions:");
        list.traverse();

        // Delete operations
        list.deleteAtStart();
        list.deleteAtEnd();
        list.deleteAtPosition(1);

        System.out.println("After Deletions:");
        list.traverse();

        // Search
        System.out.println("Search 20: " + list.search(20));
        System.out.println("Search 100: " + list.search(100));

        // Length
        System.out.println("Length: " + list.length());

        // Reverse
        list.reverse();
        System.out.println("After Reverse:");
        list.traverse();
    }
}
