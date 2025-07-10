/**
 * BFS -> Explore level by level, queue, shortest Path
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int level(TreeNode* root) {
  if(!root) return 0;
  return 1 + max(level(root->left), level(root->right));
}

//! this level order traversal is BFS
void level_order_traversal(TreeNode* root) {
  queue<TreeNode*> q;
  q.push(root);

  int lvl = level(root);
  int i = 0;

  while (!q.empty()) {
    TreeNode* temp = q.front();
    q.pop();

    // to it
    cout << temp->val << " ";

    // Signature step
    if (temp->left) q.push(temp->left);
    if (temp->right) q.push(temp->right);
  }
}

int main() {
  // Example Tree:
  //          1
  //        /   \
  //       2     3
  //      / \   / \
  //     4   5 6   7

  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  level_order_traversal(root);
}
