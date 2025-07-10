/**
 * * it is level order traversal -> array is in level order -> BFS
 */
#include <bits/stdc++.h>
using namespace std;

class node {
 public:
  int val;
  node *left;
  node *right;
  node(int val) {
    this->left = NULL;
    this->right = NULL;
    this->val = val;
  }
};

// BFS level-order print
void level_order_print(node *root, vector<vector<int>> &ans) {
  if (!root) return;

  queue<node *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    vector<int> level;

    for (int i = 0; i < n; i++) {
      node *curr = q.front();
      q.pop();
      level.push_back(curr->val);

      if (curr->left) q.push(curr->left);
      if (curr->right) q.push(curr->right);
    }
    ans.push_back(level);
  }
}

node *construct(vector<int> &arr, int n) {
  if (n == 0 || arr[0] == INT_MIN) return NULL;

  node *root = new node(arr[0]);
  queue<node *> q;
  q.push(root);

  int i = 1;
  while (!q.empty() && i < n) {
    node *curr = q.front();
    q.pop();

    // Left child
    if (i < n && arr[i] != INT_MIN) {
      curr->left = new node(arr[i]);
      q.push(curr->left);
    }
    i++;

    // Right child
    if (i < n && arr[i] != INT_MIN) {
      curr->right = new node(arr[i]);
      q.push(curr->right);
    }
    i++;
  }

  return root;
}

int main() {
  // INT_MIN as placeholder for null
  vector<int> nums = {
      1,
      2, 3,
      4, 5, INT_MIN, 6,
      INT_MIN, INT_MIN, 7, 8, 9};

  node *root = construct(nums, nums.size());
  vector<vector<int>> tree_levels;
  level_order_print(root, tree_levels);

  for (const auto &level : tree_levels) {
    for (int val : level) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}
