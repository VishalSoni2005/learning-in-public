
/**
 *
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

bool search(node* root, int data) {
  if (!root) return false;

  if (root->val == data) return true;

  if (root->val > data)
    return search(root->left, data);
  else
    return search(root->right, data);
}

int main() {
  node* root = NULL;
  int arr[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 90};

  for (int i : arr) {
    root = insert(root, i);
  }

  cout << "Inorder Traversal : ";
  inorder_print(root);
  cout << endl;

  cout << "Level Wise printing: " << endl;
  level_printing(root);
  cout << endl;

  cout << "Enter a number you wanna search : ";
  int n;
  cin >> n;

  cout << "Is Present : " << search(root, n);

  return 0;
}