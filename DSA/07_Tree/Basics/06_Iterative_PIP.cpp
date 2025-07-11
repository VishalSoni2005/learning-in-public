#include <iostream>
#include <stack>
#include <vector>
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

void per_order_iterative(Node* root) {
  stack<Node*> st;
  st.push(root);

  while (!st.empty()) {
    Node* curr = st.top();
    st.pop();
    cout << curr->val << " ";
    if (curr->right) st.push(curr->right);
    if (curr->left) st.push(curr->left);
  }
  cout << endl;
}

void in_order_iterative(Node* root) {
  stack<Node*> st;
  Node* curr = root;

  while(curr or !st.empty()) {
    while(curr) {
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

void post_order_iterative(Node* root) {
  //* key is first fill up the stack and then pop and print
  //? 2 stack will be used
  if (!root) return;
  stack<Node*> s1, s2;
  s1.push(root);

  while (!s1.empty()) {
    Node* temp = s1.top();
    s1.pop();

    s2.push(temp);
    if (temp->left) s1.push(temp->left);
    if (temp->right) s1.push(temp->right);
  }

  while (!s2.empty()) {
    cout << s2.top()->val << " ";
    s2.pop();
  }
  cout << endl;
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

  per_order_iterative(root);
  in_order_iterative(root);
  post_order_iterative(root);
}