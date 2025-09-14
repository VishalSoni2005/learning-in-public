/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    // code here

    vector<vector<int>> ans;
    if (!root) return ans;
    if (!root->left and !root->right) return {{root->data}};

    queue<Node*> q;
    q.push(root);

    while (not q.empty()) {
      int size = q.size();
      vector<int> helper;

      for (int i = 0; i < size; i++) {
        Node* temp = q.front();
        q.pop();

        helper.push_back(temp->data);

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
      }
      ans.push_back(helper);
    }

    return ans;
  }
};