#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution_One {
 public:
  int level(TreeNode* root) {
    if (!root)
      return 0;
    return 1 + max(level(root->left), level(root->right));
  }

  void level_order_traversal(vector<int>& dummy, TreeNode* root, int curr,
                             int lvl) {
    if (root == NULL)
      return;
    if (curr == lvl) {
      dummy.push_back(root->val);
    }
    level_order_traversal(dummy, root->left, curr + 1, lvl);
    level_order_traversal(dummy, root->right, curr + 1, lvl);
  }

  void iteration(TreeNode* root, int n, vector<vector<int>>& ans) {
    for (int i = 0; i < n; i++) {
      vector<int> dummy;
      level_order_traversal(dummy, root, 0, i);
      ans.push_back(dummy);
    }
  }

  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root)
      return ans;
    int lvl = level(root);

    iteration(root, lvl, ans);

    for (int i = 0; i < ans.size(); i++) {
      if (i % 2 != 0) {
        reverse(ans[i].begin(), ans[i].end());
      }
    }

    return ans;
  }
};

class Solution_Two {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root)
      return ans;

    bool ltr = true;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      vector<int> helper(size);

      for (int i = 0; i < size; i++) {
        TreeNode* temp = q.front();
        q.pop();

        int idx = ltr ? i : (size - i - 1);
        helper[idx] = temp->val;

        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
      }

      ans.push_back(helper);
      ltr = !ltr;
    }

    return ans;
  }
};