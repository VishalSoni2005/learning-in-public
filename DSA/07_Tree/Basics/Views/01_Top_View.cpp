/**
 * left view
 * right view
 * top view
 * bottom view
 * diagonal traversal -> diagonal view
 * vertical order traversal -> virtical view
 * sprial view
 */

#include <bits/stdc++.h>
using namespace std;

class node {
 public:
  int val;
  node* left;
  node* right;

  node(int val) {
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }

  bool isLeaf() {
    return left == nullptr and right == nullptr;
  }
};

int level(node* root) {
  if (root == NULL)
    return 0;
  return 1 + max(level(root->left), level(root->right));
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

  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->right = new node(6);

  root->left->right->left = new node(7);
  root->right->right->left = new node(8);
  root->right->right->right = new node(9);

  root->left->right->left->left = new node(10);
  root->left->right->left->right = new node(11);
}
