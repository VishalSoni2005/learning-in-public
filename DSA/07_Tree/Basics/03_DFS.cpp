/**
 * DFS (Depth-First Search) is a tree traversal method
 * where you explore as deep as possible along one branch before backtracking.
 *
 */

#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* root) {
  if (!root) return;
  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(TreeNode* root) {
  if (!root) return;
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

void postorder(TreeNode* root) {
  if (!root) return;
  postorder(root->left);
  postorder(root->right);
  cout << root->val << " ";
}

int main() {
  // Example Tree:
  //         1
  //        / \
  //       2   3
  //      / \
  //     4   5

  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  cout << "Preorder DFS: ";
  preorder(root);
  cout << endl;

  cout << "Inorder DFS: ";
  inorder(root);
  cout << endl;

  cout << "Postorder DFS: ";
  postorder(root);
  cout << endl;

  return 0;
}
