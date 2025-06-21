// Linked List Implementation
// Singly Linked List (Insert, Delete, Traverse)

#include <iostream>
using namespace std;

class node
{
public:
  int val;
  node *next;

  node(int val)
  {
    this->val = val;
    this->next = NULL;
  }
};

class linkedList
{
public:
  node *head;
  // node *tail;
  int size;
  linkedList()
  {
    head = NULL;
    // tail = NULL;
    size = 0;
  }

  void insertAtHead(int value)
  {
    node *newNode = new node(value);

    if (size == 0)
    {
      head = newNode;
    }
    else
    {
      newNode->next = head;
      head = newNode;
    }
    size++;
  }

  void insertAtTail(int value)
  {
    node *newNode = new node(value);
    if (size == 0)
      head = newNode;
    else
    {
      node *temp = head;
      while (temp->next != nullptr)
      {
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->next = nullptr;
    }
    size++;
  }
  void insertAtPosition(int value, int position)
  {

    if (position < 0 || position > size)
    {
      cout << "Invalid Index\n";
      return;
    }

    if (position == 0)
    {
      insertAtHead(value);
      return;
    }
    if (position == size)
    {
      insertAtTail(value);
      return;
    }

    else
    {
      node *newNode = new node(value);
      node *temp = head;
      for (int i = 1; i < position; i++)
        temp = temp->next;
      newNode->next = temp->next;
      temp->next = newNode;
      size++;
    }
  }

  void deleteAtHead()
  {
    node *temp = head;
    head = head->next;
    delete temp;
    size--;
  }
  void deleteAtTail()
  {
    if (size == 0)
      return;
    if (size == 1)
    {
      delete head;
      head = NULL;
    }
    else
    {
      node *temp = head;
      while (temp->next->next != nullptr)
        temp = temp->next;
      delete temp->next; // Actually delete the last node
      temp->next = NULL;
    }
    size--;
  }

  void deleteAtPosition(int position)
  {
    if (position < 0 || position >= size)
    {
      cout << "Invalid Position ";
      return;
    }
    if (position == 0)
    {
      deleteAtHead();
      return;
    }
    if (position == size)
    {
      deleteAtTail();
      return;
    }

    else
    {
      node *temp = head;
      for (int i = 1; i < position; i++)
        temp = temp->next;
      node *toDelete = temp->next;
      temp->next = temp->next->next;
      delete toDelete;
      size--;
    }
  }

  void display()
  {
    node *temp = head;
    while (temp != nullptr)
    {
      cout << temp->val << " -> ";
      temp = temp->next;
    }
    cout << "NULL\n";
  }
  int getSize()
  {
    return size;
  }
  bool isEmpty()
  {
    return size == 0;
  }
  node *getHead()
  {
    return head;
  }
  node *getTail()
  {
    if (size == 0)
      return nullptr;
    node *temp = head;
    while (temp->next != nullptr)
      temp = temp->next;
    return temp;
  }
  void clear()
  {
    while (!isEmpty())
    {
      deleteAtHead();
    }
  }
  ~linkedList()
  {
    clear();
  }
};

// int main()
// {
//   linkedList ll;
//   for (int i = 0; i < 10; i++)
//     ll.insertAtPosition((i + 1) * 10, i); // value, position

//   ll.display(); // Output: 10 -> 20 -> 30 -> ... -> 100 -> NULL
// }
int main()
{
  linkedList ll;

  // Test 1: Check if list is initially empty
  cout << "Test 1: Initial list\n";
  cout << "Is empty? " << (ll.isEmpty() ? "Yes" : "No") << endl; // Expected: Yes
  cout << "Size: " << ll.getSize() << endl;                      // Expected: 0
  ll.display();                                                  // Expected: NULL
  cout << "-----------------------------\n";

  // Test 2: Insert at head and tail
  cout << "Test 2: Insert at head and tail\n";
  ll.insertAtHead(30);
  ll.insertAtHead(20);
  ll.insertAtHead(10);
  ll.insertAtTail(40);
  ll.insertAtTail(50);
  ll.display();                                  // Expected: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
  cout << "Size: " << ll.getSize() << endl;      // Expected: 5
  cout << "Head: " << ll.getHead()->val << endl; // Expected: 10
  cout << "Tail: " << ll.getTail()->val << endl; // Expected: 50
  cout << "-----------------------------\n";

  // Test 3: Insert at positions (head, middle, tail)
  cout << "Test 3: Insert at positions\n";
  ll.insertAtPosition(5, 0);                // New head
  ll.insertAtPosition(25, 3);               // Middle
  ll.insertAtPosition(60, 7);               // New tail
  ll.display();                             // Expected: 5 -> 10 -> 20 -> 25 -> 30 -> 40 -> 50 -> 60 -> NULL
  cout << "Size: " << ll.getSize() << endl; // Expected: 8
  cout << "-----------------------------\n";

  // Test 4: Invalid position insertions
  cout << "Test 4: Invalid position insertions\n";
  ll.insertAtPosition(100, -1); // Should print "Invalid Index"
  ll.insertAtPosition(100, 9);  // Should print "Invalid Index"
  ll.display();                 // List should remain unchanged
  cout << "-----------------------------\n";

  // Test 5: Delete at head and tail
  cout << "Test 5: Delete at head and tail\n";
  ll.deleteAtHead();
  ll.deleteAtTail();
  ll.display();                             // Expected: 10 -> 20 -> 25 -> 30 -> 40 -> 50 -> NULL
  cout << "Size: " << ll.getSize() << endl; // Expected: 6
  cout << "-----------------------------\n";

  // Test 6: Delete at positions (head, middle, tail)
  cout << "Test 6: Delete at positions\n";
  ll.deleteAtPosition(0);                   // New head (delete 10)
  ll.deleteAtPosition(2);                   // Middle (delete 30)
  ll.deleteAtPosition(3);                   // New tail (delete 50)
  ll.display();                             // Expected: 20 -> 25 -> 40 -> NULL
  cout << "Size: " << ll.getSize() << endl; // Expected: 3
  cout << "-----------------------------\n";

  // Test 7: Invalid position deletions
  cout << "Test 7: Invalid position deletions\n";
  ll.deleteAtPosition(-1); // Should print "Invalid Position"
  ll.deleteAtPosition(3);  // Should print "Invalid Position" (size is 3, max index is 2)
  ll.display();            // List should remain unchanged
  cout << "-----------------------------\n";

  // Test 8: Clear the list
  cout << "Test 8: Clear the list\n";
  ll.clear();
  cout << "Is empty? " << (ll.isEmpty() ? "Yes" : "No") << endl; // Expected: Yes
  cout << "Size: " << ll.getSize() << endl;                      // Expected: 0
  ll.display();                                                  // Expected: NULL
  cout << "-----------------------------\n";

  // Test 9: Operations on empty list
  cout << "Test 9: Operations on empty list\n";
  ll.deleteAtHead();      // Should handle gracefully
  ll.deleteAtTail();      // Should handle gracefully
  ll.deleteAtPosition(0); // Should print "Invalid Position"
  ll.display();           // Expected: NULL
  cout << "-----------------------------\n";

  // Test 10: Mixed operations
  cout << "Test 10: Mixed operations\n";
  ll.insertAtHead(100);
  ll.insertAtTail(200);
  ll.insertAtPosition(150, 1);
  ll.deleteAtHead();
  ll.insertAtPosition(50, 0);
  ll.deleteAtTail();
  ll.insertAtTail(300);
  ll.deleteAtPosition(1);
  ll.display();                                  // Expected: 50 -> 300 -> NULL
  cout << "Size: " << ll.getSize() << endl;      // Expected: 2
  cout << "Head: " << ll.getHead()->val << endl; // Expected: 50
  cout << "Tail: " << ll.getTail()->val << endl; // Expected: 300
  cout << "-----------------------------\n";

  // Test 11: Destructor test (automatic when main ends)
  cout << "Test 11: Destructor will be called automatically\n";

  return 0;
}