class Solution {
 public:
  unordered_map<int, int> inorderIndex;

  TreeNode* build(vector<int>& pre, int& preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    int rootVal = pre[preIndex++];
    TreeNode* root = new TreeNode(rootVal);

    int inIndex = inorderIndex[rootVal];

    root->left = build(pre, preIndex, inStart, inIndex - 1);
    root->right = build(pre, preIndex, inIndex + 1, inEnd);

    return root;
  }

  TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
    int n = pre.size();
    for (int i = 0; i < n; ++i) {
      inorderIndex[in[i]] = i;
    }
    int preIndex = 0;
    return build(pre, preIndex, 0, n - 1);
  }
};
