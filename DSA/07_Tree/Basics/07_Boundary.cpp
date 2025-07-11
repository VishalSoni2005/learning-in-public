/**
 * boundary traversal clockwise
 * boundary traversal anti-clockwise
 * only print left/right boundary
 * iterative boundary traversal
 * print all leaf
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;

  Node(int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
  }

  bool isLeaf() {
    return left == nullptr and right == nullptr;
  }
};

// todo: HELPER FUNTIONS REQUIRED FOR THIS CASES -------------

void print_leaf(Node* root) {
  if (!root) return;
  print_leaf(root->left);
  if (root->isLeaf()) cout << root->val << " ";
  print_leaf(root->right);
}
void print_left_boundary_normal(Node* root) {
  Node* curr = root;
  while (curr) {
    if (!curr->isLeaf()) cout << curr->val << " ";
    curr = curr->left ? curr->left : curr->right;
  }
}
void print_left_boundary_reverse(Node* root) {
  stack<int> st;
  Node* curr = root;

  while (curr) {
    if (!curr->isLeaf()) st.push(curr->val);
    curr = curr->left ? curr->left : curr->right;
  }

  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
}
void print_right_boundary_normal(Node* root) {
  Node* curr = root;
  while (curr) {
    if (!curr->isLeaf()) cout << curr->val << " ";
    curr = curr->right ? curr->right : curr->left;
  }
}
void print_right_boundary_reverse(Node* root) {
  stack<int> st;
  Node* curr = root;

  while (curr) {
    if (!curr->isLeaf()) st.push(curr->val);
    curr = curr->right ? curr->right : curr->left;
  }
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
}

// helper funtions end ---------------------------------------

void print_boundary_clockwise(Node* root) {
  if (!root) return;
  cout << root->val << " ";

  // right boundary (excluding leaf) -- FIXED LINE
  print_right_boundary_normal(root->right);

  // All leaves
  print_leaf(root->right);
  print_leaf(root->left);

  // left boundary in reverse (excluding leaf)
  print_left_boundary_reverse(root->left);
}

void print_boundary_anticlockwise(Node* root) {
  if (!root) return;
  cout << root->val << " ";

  // Left boundary (excluding leaf)
  print_left_boundary_normal(root->left);

  // All leaves
  print_leaf(root->left);
  print_leaf(root->right);

  // Right boundary in reverse (excluding leaf)
  print_right_boundary_reverse(root->right);
}

void print_boundary_clockwise_iterative(Node* root) {
  if (!root) return;

  // print right boundary
  Node* curr = root;
  while (curr) {
    if (!curr->isLeaf()) cout << curr->val << " ";
    curr = curr->right ? curr->right : curr->left;
  }

  // print leaf nodes (reverse inorder)
  stack<Node*> st;
  curr = root;
  while (curr || !st.empty()) {
    while (curr) {
      st.push(curr);
      curr = curr->right;
    }

    curr = st.top();
    st.pop();
    if (curr->isLeaf()) cout << curr->val << " ";
    curr = curr->left;
  }

  // left boundary in reverse
  stack<int> sl;
  Node* curr2 = root->left;
  while (curr2) {
    if (!curr2->isLeaf()) sl.push(curr2->val);
    curr2 = curr2->left ? curr2->left : curr2->right;
  }
  while (!sl.empty()) {
    cout << sl.top() << " ";
    sl.pop();
  }
}

void print_boundary_anticlockwise_iterative(Node* root) {
  if (!root) return;
  cout << root->val << " ";

  Node* curr;

  // LEFT BOUNDARY
  curr = root->left;
  while (curr) {
    if (!curr->isLeaf()) cout << curr->val << " ";
    curr = curr->left ? curr->left : curr->right;
  }

  // LEAVES (Inorder)
  stack<Node*> s;
  curr = root;
  while (curr || !s.empty()) {
    while (curr) {
      s.push(curr);
      curr = curr->left;
    }
    curr = s.top();
    s.pop();
    if (curr->isLeaf()) cout << curr->val << " ";
    curr = curr->right;
  }

  // RIGHT BOUNDARY (bottom-up)
  stack<int> rb;
  curr = root->right;
  while (curr) {
    if (!curr->isLeaf()) rb.push(curr->val);
    curr = curr->right ? curr->right : curr->left;
  }
  while (!rb.empty()) {
    cout << rb.top() << " ";
    rb.pop();
  }
}

int main() {
  /*
        Constructing the following complex tree:
                 1
              /     \
            2         3
          /   \        \
         4     5        6
              /        / \
             7        8   9
            / \
          10  11
  */

  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(6);

  root->left->right->left = new Node(7);
  root->right->right->left = new Node(8);
  root->right->right->right = new Node(9);

  root->left->right->left->left = new Node(10);
  root->left->right->left->right = new Node(11);

  //* all iterative traversing algorithms
  // anticlockwise-> 1 2 4 10 11 8 9 6 3
  // clockwise-> 1 3 6 9 8 11 10 4 2

  cout << "Anti-clockwise Boundary Traversal (Recursive):\n";
  print_boundary_anticlockwise(root);

  cout << "\n\nClockwise Boundary Traversal (Recursive):\n";
  print_boundary_clockwise(root);

  cout << "\n\nAnti-clockwise Boundary Traversal (Iterative):\n";
  print_boundary_anticlockwise_iterative(root);

  cout << "\n\nClockwise Boundary Traversal (Iterative):\n";
  print_boundary_clockwise_iterative(root);
}