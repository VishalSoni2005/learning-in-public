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
}
void print_right_boundary_normal(Node* root) {
}
void print_right_boundary_reverse(Node* root) {
}

// helper funtions end ---------------------------------------

void print_boundary_clockwise(Node* root) {
}
void print_boundary_anticlockwise(Node* root) {
}
void print_boundary_clockwise_iterative(Node* root) {
}
void print_boundary_anticlockwise_iterative(Node* root) {
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
  // anticlockwise-> 1 2 3 10 1 8 9 6 3
  // clockwise-> 1 3 6 9 8 11 10 4 2

}