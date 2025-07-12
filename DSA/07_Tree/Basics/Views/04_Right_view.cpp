/**
 * * See the intutuion is print the last node value of level order traversal
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right;

  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

// Should return  right view of tree
class Solution {
 public:
  // Function to return list containing elements of right view of binary tree.
  vector<int> rightView(Node* root) {
    // Your Code here
    vector<int> ans;
    if (!root) return ans;

    // level order traversal bfs
    // at all level, return first node value
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      int level = q.size();
      for (int i = 0; i < level; i++) {
        Node* temp = q.front();
        q.pop();

        if (i == level - 1) ans.push_back(temp->data); //! most imp step

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
      }
    }

    return ans;
  }
};