#include <bits/stdc++.h>
using namespace std;

//! insertion time complexities: O(n log n)

class node {
 public:
  int data;
  int height;
  node* left;
  node* right;

  node(int val) {
    data = val;
    height = 1;
    left = right = NULL;
  }
};

int getHeight(node* root) {
  if (!root) return 0;
  return root->height;
}

int getBalance(node* root) {
  return root ? getHeight(root->left) - getHeight(root->right) : 0;
}

node* rightRotation(node* root) {
  node* child = root->left;
  node* childRight = child->right;

  // Rotation
  child->right = root;
  root->left = childRight;

  // Update heights
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  child->height = 1 + max(getHeight(child->left), getHeight(child->right));

  return child;
}

node* leftRotation(node* root) {
  node* child = root->right;
  node* childLeft = child->left;

  // Rotation
  child->left = root;
  root->right = childLeft;

  // Update heights
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  child->height = 1 + max(getHeight(child->left), getHeight(child->right));

  return child;
}

node* insert(node* root, int key) {
  // Step 1: Normal BST insertion
  if (!root) return new node(key);

  if (key < root->data)
    root->left = insert(root->left, key);
  else if (key > root->data)
    root->right = insert(root->right, key);
  else
    return root;  // No duplicate values allowed

  // Step 2: Update height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));

  // Step 3: Get balance factor
  int balance = getBalance(root);

  // Step 4: Balance the tree
  // Case 1: Left Left
  if (balance > 1 && key < root->left->data)
    return rightRotation(root);

  // Case 2: Right Right
  if (balance < -1 && key > root->right->data)
    return leftRotation(root);

  // Case 3: Left Right
  if (balance > 1 && key > root->left->data) {
    root->left = leftRotation(root->left);
    return rightRotation(root);
  }

  // Case 4: Right Left
  if (balance < -1 && key < root->right->data) {
    root->right = rightRotation(root->right);
    return leftRotation(root);
  }

  return root;  // return unchanged node
}

// Optional: Inorder traversal to verify the tree
void inorder(node* root) {
  if (!root) return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

node* deleteInBst(node* root, int key) {
  if (!root) return nullptr;

  if (root->data > key) {
    root->left = deleteInBst(root->left, key);
    return root;
  } else if (root->data < key) {
    root->right = deleteInBst(root->right, key);
    return root;
  }

  else {
    // leaf node
    if (!root->left || !root->right) {
      node* temp = root->left ? root->left : root->right;
      delete root;
      return temp;
    }

    // both child
    else {
      node* parent = root;
      node* child = root->left;

      while (child->right) {
        parent = child;
        child = child->right;
      }

      if (parent != child) {
        parent->right = child->left;
        child->right = root->right;
        child->left = root->left;
        delete root;
        return child;
      } else {
        child->right = root->right;
        delete root;
        return child;
      }
    }
  }

  // Step 2: Update height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));

  // Step 3: Get balance factor
  int balance = getBalance(root);

  // Step 4: Balance the tree
  // Case 1: Left Left
  if (balance > 1 && key < root->left->data)
    return rightRotation(root);

  // Case 2: Right Right
  if (balance < -1 && key > root->right->data)
    return leftRotation(root);

  // Case 3: Left Right
  if (balance > 1 && key > root->left->data) {
    root->left = leftRotation(root->left);
    return rightRotation(root);
  }

  // Case 4: Right Left
  if (balance < -1 && key < root->right->data) {
    root->right = rightRotation(root->right);
    return leftRotation(root);
  }

  return root;  // return unchanged node
}

int main() {
  node* root = NULL;

  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 50);
  root = insert(root, 70);
  root = insert(root, 5);
  root = insert(root, 100);
  root = insert(root, 95);

  cout << "Inorder traversal of AVL Tree:\n";
  inorder(root);
  cout << endl;

  return 0;
}
