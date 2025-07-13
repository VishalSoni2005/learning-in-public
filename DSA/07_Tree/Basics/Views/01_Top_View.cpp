/**
 * left view
 * right view
 * top view
 * bottom view
 * diagonal traversal -> diagonal view
 * vertical order traversal -> virtical view
 * sprial view
 */
#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int data) : data(data), left(NULL), right(NULL) {}
};
class Solution {
 public:
  void find(Node *root, int pos, int &l, int &r) {
    if (!root) return;
    l = min(pos, l);
    r = max(pos, r);
    find(root->left, pos - 1, l, r);
    find(root->right, pos + 1, l, r);
  }

  vector<int> topView(Node *root) {
    if (!root) return {};

    int l = 0, r = 0;
    find(root, 0, l, r);  // find leftmost and rightmost horizontal distances

    int width = r - l + 1;  // total number of vertical lines
    vector<int> ans(width);
    vector<bool> filled(width, false);

    queue<Node *> q;
    queue<int> index;

    q.push(root);
    index.push(-l);  // shift so root is at index -l (zero-based index)

    while (!q.empty()) {
      Node *node = q.front();
      q.pop();
      int pos = index.front();
      index.pop();

      if (!filled[pos]) {
        filled[pos] = true;
        ans[pos] = node->data;
      }

      if (node->left) {
        q.push(node->left);
        index.push(pos - 1);
      }

      if (node->right) {
        q.push(node->right);
        index.push(pos + 1);
      }
    }

    return ans;
  }
};
