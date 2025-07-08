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

int height(node* root) {
  if (root == NULL) return 0;
  return 1 + max(height(root->left), height(root->right));
}
void level_order(node* root, int curr, int level) {
  if (root == NULL) return;
  if (curr == level) {
    cout << root->val << " ";
    return;
  }

  level_order(root->left, curr + 1, level);
  level_order(root->right, curr + 1, level);
}

void level_iteration(node* root) {
  int n = height(root);

  for (int i = 0; i < n; i++) {
    level_order(root, 0, i);
    cout << endl;
  }
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

  cout << "Level wise printing " << endl;
  level_iteration(root);

  return 0;
}
