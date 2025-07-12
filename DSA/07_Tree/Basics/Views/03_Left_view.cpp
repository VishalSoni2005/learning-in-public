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

class Solution {
 public:
  vector<int> leftView(Node* root) {

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

        if (i == 0) ans.push_back(temp->data);

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
      }
    }

    return ans;
  }
};