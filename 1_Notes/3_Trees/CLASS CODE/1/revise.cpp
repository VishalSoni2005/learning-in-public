#include<bits/stdc++.h>
using namespace std;
class node{
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
// int levels(node* root) {
//     if(root == NULL) return 0;
//     return 1 + max(levels(root->left), levels(root->right));
// }
// int maxInTree(node* root) {
//     if(root == NULL) return INT_MIN;
//     return max(root->val, max(maxInTree(root->left), maxInTree(root->right)));
// }
// int size(node* root) {
//     if(root == NULL) return 0;
//     return 1 + size(root->left) + size(root->right);
// }
// int sum(node* root) {
//     if(root == NULL) return 0;
//     return root->val + sum(root->left) + sum(root->right);
// }
int maxInTree(node* root) {
    if(root == nullptr) return 0;
    return max(root->val, max(maxInTree(root->left),maxInTree(root->right)));
}
int main() {
    node* a = new node(10);
    node* b = new node(10);
    node* c = new node(10);
    node* d = new node(10000);
    node* e = new node(0010);
    node* f = new node(10);
    node* g = new node(100);

    
    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

    cout << maxInTree(a);



}