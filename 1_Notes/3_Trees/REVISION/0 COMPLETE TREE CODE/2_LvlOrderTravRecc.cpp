#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int val = 0;
    node* left;
    node* right;
    node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
int levels(node* root) {
    if(!root) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
void lvlOrder(node* root, int curr, int level) {
    if(!root) return ;
    if(curr == level) {
        cout << root->val << " ";
        return;
    }
    lvlOrder(root->left, curr+1, level);
    lvlOrder(root->right, curr+1, level);
}
int iteration(node* root) {
    int n = levels(root);
    for(int i=0; i<n; i++) {
        lvlOrder(root, 0, i);
        cout << endl;
    }
}
int main() {
    node* a = new node(10);
    node* b = new node(20);
    node* c = new node(30);
    node* d = new node(40);
    node* e = new node(50);
    node* f = new node(60);
    node* g = new node(70);
    node* h = new node(80);
    node* i = new node(100);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    d->right = g;
    e->left = h;
    h->left = i;

    iteration(a);
}