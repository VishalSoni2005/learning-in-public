/**
 * * height / level
 * * size
 * * max
 * * min
 * * diameter
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
};

int level(node* root) {
  if (root == NULL)
    return 0;
  return 1 + max(level(root->left), level(root->right));
}

void helper(node* root, int& maxDia) {
  if (root == NULL)
    return;

  int leftHeight = level(root->left);
  int rightHeight = level(root->right);

  int dia = leftHeight + rightHeight;

  maxDia = max(dia, maxDia);
  helper(root->left, maxDia);
  helper(root->right, maxDia);
}
int diameter(node* root) {
  //! key intuition is : diameter is max(root->left + root->right)
  //? sub optimal code : return level(root->left) + level(root->right);
  int maxDia = 0;
  helper(root, maxDia);
  return maxDia;
}

int maxInTree(node* root) {
  if (root == nullptr) return INT_MIN;
  return max(root->val, max(maxInTree(root->left), maxInTree(root->right)));
}

int minInTree(node* root) {
  if (root == NULL) return INT_MAX;
  return min(root->val, min(minInTree(root->left), minInTree(root->right)));
}

int height(node* root) {
  if (root == NULL) return 0;
  return 1 + max(height(root->left), height(root->right));
}

int size(node* root) {
  if (root == nullptr) return 0;
  return 1 + size(root->left) + size(root->right);
}

int main() {
  cout << "Following Algo follow the level wise filling ." << endl;

  int n;
  cout << "Enter Root Element : ";
  cin >> n;

  int first;
  int second;

  node* root = new node(n);
  queue<node*> tree;
  tree.push(root);

  while (!tree.empty()) {
    node* temp = tree.front();
    tree.pop();

    cout << "Enter left child of " << temp->val << " (-1 for NULL): ";
    cin >> first;
    if (first != -1) {
      temp->left = new node(first);
      tree.push(temp->left);
    }

    cout << "Enter right child of " << temp->val << " (-1 for NULL): ";
    cin >> second;
    if (second != -1) {
      temp->right = new node(second);
      tree.push(temp->right);
    }
  }

  cout << "Level Wise Traversal  " << endl;

  cout << "Height of Tree : " << height(root) << endl;
  cout << "Size of tree : " << size(root) << endl;
  cout << "Min of tree : " << minInTree(root) << endl;
  cout << "Max of Tree : " << maxInTree(root) << endl;
  cout << "Diameter of Tree : " << diameter(root) << endl;

  return 0;
}
