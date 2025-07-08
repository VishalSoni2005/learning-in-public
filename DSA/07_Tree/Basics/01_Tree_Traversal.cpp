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

void displayPre(node* root) {
  if (root == nullptr) return;
  cout << root->val << " ";
  displayPre(root->left);
  displayPre(root->right);
}
void displayIn(node* root) {
  if (root == nullptr) return;
  displayIn(root->left);
  cout << root->val << " ";
  displayIn(root->right);
}
void displayPost(node* root) {
  if (root == nullptr) return;
  displayPost(root->left);
  displayPost(root->right);
  cout << root->val << " ";
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

  cout << endl;
  cout << "Preorder : ";
  displayPre(root);
  cout << endl;
  cout << "Inorder : ";
  displayIn(root);
  cout << endl;
  cout << "Postorder : ";
  displayPost(root);

  return 0;
}
