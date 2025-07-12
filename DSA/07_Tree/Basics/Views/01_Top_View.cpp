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

void topView(node* root) {
  if (!root) return;

  map<int, int> top;  // hd -> node val
  queue<pair<node*, int>> q;

  q.push({root, 0});

  while (!q.empty()) {
    auto [curr, hd] = q.front();
    q.pop();

    if (top.find(hd) == top.end())
      top[hd] = curr->val;

    if (curr->left) q.push({curr->left, hd - 1});
    if (curr->right) q.push({curr->right, hd + 1});
  }

  for (auto [hd, val] : top)
    cout << val << " ";
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

  // top view: 4 2 1 3 6 9
  topView(root);
}
