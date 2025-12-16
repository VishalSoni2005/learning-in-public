/**
 * ? 🔰 1. Basic BST Concepts
    Definition: A binary tree where for every node:
    Left subtree contains only nodes with values less than the node's value.
    Right subtree contains only nodes with values greater than the node's value.

    No duplicates (usually, unless stated otherwise).
*/

/**
 * ?
● Insertion
● Traversal - Inorder, Preorder, Postorder
● Searching
● Deletion
● Min/max
●
*/

/**
 * ! very important :
 * * time complxity of inserting on tree = O( height ) -> as on observation, all new val is attaches to leaf node
 * * Best answer: "It’s O(height of the tree), which is O(log n) for a balanced BST and O(n) in the worst-case skewed tree."
 * TC to find height of tree -> O(n) -> as i visit every node once
 *
 *  Time Complexity to Create a Binary Search Tree (BST): Total Time Complexity = O(n × h)
 */

#include <bits/stdc++.h>
using namespace std;

class node {
 public:
  int val;
  node* left;
  node* right;

  node(int val) : val(val), left(NULL), right(NULL) {}
};

void inorder_print(node* root) {
  if (!root) return;
  inorder_print(root->left);
  cout << root->val << " ";
  inorder_print(root->right);
}

node* insert(node* root, int key) {
  if (!root) return new node(key);

  if (root->val < key)
    root->right = insert(root->right, key);

  else if (root->val >= key)
    root->left = insert(root->left, key);

  return root;
}

void level_printing(node* root) {
  queue<node*> q;
  q.push(root);

  while (!q.empty()) {
    int level = q.size();
    for (int i = 0; i < level; i++) {
      node* temp = q.front();
      q.pop();

      cout << temp->val << " ";

      if (temp->left) q.push(temp->left);
      if (temp->right) q.push(temp->right);
    }
    cout << endl;
  }
}

int main() {
  node* root = NULL;
  int arr[] = {50, 30, 70, 20, 40, 60, 80};

  for (int i : arr) {
    root = insert(root, i);
  }

  cout << "Inorder Traversal : ";
  inorder_print(root);
  cout << endl;

  cout << "Level Wise printing: " << endl;
  level_printing(root);
  cout << endl;

  return 0;
}