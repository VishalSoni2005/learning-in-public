#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;

  Node(int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
  }
};

void in_order_iterative(Node* root) {
  stack<Node*> st;
  Node* curr = root;

  while (curr or !st.empty()) {
    while (curr) {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();
    cout << curr->val << " ";
    curr = curr->right;
  }
  cout << endl;
}

vector<int> morris_inorder(Node* root) {
  vector<int> ans;

  while (root) {
    if (root->left == nullptr) {
      ans.push_back(root->val);
      root = root->right;
    } else {
      Node* curr = root->left;

      while (curr->right and curr->right != root) {
        curr = curr->right;
      }

      if (curr->right == NULL) {
        curr->right = root;
        root = root->left;
      } else {
        curr->right = NULL;
        ans.push_back(root->val);
        root = root->right;
      }
    }
  }
  return ans;
}

vector<int> morris_preorder(Node* root) {
  vector<int> ans;
  while (root) {
    if (!root->left) {
      ans.push_back(root->val);
      root = root->right;
    } else {
      Node* curr = root->left;

      while (curr->right and curr->right != root) {
        curr = curr->right;
      }

      if (curr->right == NULL) {
        ans.push_back(root->val);
        curr->right = root;
        root = root->left;
      } else {
        curr->right = NULL;
        root = root->right;
      }
    }
  }
  return ans;
}

int main() {
  /*
        Constructing the following complex tree:
                 1
              /     \
            2         3
          /   \        \
         4     5        6
              /        / \
             7        8   9
            / \
          10  11
  */

  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(6);

  root->left->right->left = new Node(7);
  root->right->right->left = new Node(8);
  root->right->right->right = new Node(9);

  root->left->right->left->left = new Node(10);
  root->left->right->left->right = new Node(11);

  //* all iterative traversing algorithms

  in_order_iterative(root);
  cout << endl;

  vector<int> morrisInorder = morris_inorder(root);
  for (auto i : morrisInorder) cout << i << " ";
}