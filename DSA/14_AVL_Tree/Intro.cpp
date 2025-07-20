#include <bits/stdc++.h>
using namespace std;

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
  return root ? root->height : 0;
}

int getBalance(node* root) {
  return root ? getHeight(root->left) - getHeight(root->right) : 0;
}

node* rightRotation(node* y) {
  node* x = y->left;
  node* T2 = x->right;

  // Rotation
  x->right = y;
  y->left = T2;

  // Update heights
  y->height = 1 + max(getHeight(y->left), getHeight(y->right));
  x->height = 1 + max(getHeight(x->left), getHeight(x->right));

  return x;
}

node* leftRotation(node* x) {
  node* y = x->right;
  node* T2 = y->left;

  // Rotation
  y->left = x;
  x->right = T2;

  // Update heights
  x->height = 1 + max(getHeight(x->left), getHeight(x->right));
  y->height = 1 + max(getHeight(y->left), getHeight(y->right));

  return y;
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

// #include <bits/stdc++.h>
// using namespace std;

// class node {
//  public:
//   int data;
//   int height;

//   node* left;
//   node* right;

//   node(int val) {
//     this->data = val;
//     height = 1;
//     left = right = NULL;
//   }
// };

// int getHeight(node* root) {
//   if (!root) return 0;
//   return root->height;
// }

// int getBalance(node* root) {
//   return getHeight(root->left) - getHeight(root->right);
// }

// node* rightRotation(node* root) {


// }
// node* leftRotation(node* root) {
// }

// node* insert(node* root, int key) {
//   if (!root) return new node(key);

//   // if exist
//   if (key < root->data) {
//     root->left = insert(root->left, key);
//   }

//   else if (key > root->data) {
//     root->right = insert(root->right, key);
//   }

//   else
//     return root;

//   // update height
//   root->height = 1 + max(getHeight(root->left), getHeight(root->right));

//   // checking balancing
//   int balance = getBalance(root);

//   //? balancing cases
//   // 1 Left Left case
//   if (balance > 1 and root->left->data > key) {
//     rightRotation(root);
//   }

//   // 2 right right case

//   else if (balance < -1 and root->right->data < key) {
//     leftRotation(root);
//   }
//   // 3 left right case
//   else if (balance > 1 and root->left->data < key) {
//     leftRotation(root->left);
//     rightRotation(root);
//   }

//   // 4 right left case
//   else if (balance < -1 and root->left->data > key) {
//     rightRotation(root->right);
//     leftRotation(root);

//   }
//   // no balancing
//   else {
//     return root;
//   }
// }

// int main() {
//   node* root = NULL;

//   //* no dublicate element are allowed
//   root = insert(root, 10);
//   root = insert(root, 20);
//   root = insert(root, 30);
//   root = insert(root, 50);
//   root = insert(root, 70);
//   root = insert(root, 5);
//   root = insert(root, 100);
//   root = insert(root, 95);
//   // root = insert(root, 10);
//   // root = insert(root, 10);
//   // root = insert(root, 10);
//   // root = insert(root, 10);
//   // root = insert(root, 10);
//   // root = insert(root, 10);
//   // root = insert(root, 10);
//   // root = insert(root, 10);
//   return 0;
// }