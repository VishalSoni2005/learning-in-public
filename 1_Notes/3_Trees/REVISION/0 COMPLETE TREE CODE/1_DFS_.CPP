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

void PreOrderDisplay(node* root){
    if(root == NULL) return ;
    cout << root->val << " ";
    PreOrderDisplay(root->left);
    PreOrderDisplay(root->right);
}
void InOrderDisplay(node* root){
    if(root == NULL) return ;
    InOrderDisplay(root->left);
    cout << root->val << " ";
    InOrderDisplay(root->right);
}
void PostOrderDisplay(node* root){
    if(root == NULL) return ;
    PostOrderDisplay(root->left);
    PostOrderDisplay(root->right);
    cout << root->val << " ";
}
int sum(node* root){
    if(root == NULL) return 0;
    return root->val + sum(root->left) + sum(root->right);
} 
int size(node* a){
    if(a == NULL) return 0;
    return 1 + size(a->left) + size(a->right);
}
int maxx(node* root) {
    if(root == NULL) return INT_MIN;
    return max(root->val, max(maxx(root->left), maxx(root->right)));
}
int height(node* root) {
    if(root == NULL) return -1;
    return 1 + max(height(root->left), height(root->right));
}
int levels(node* root) {
    if(root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
int dia(node* root) {
    return levels(root->left) + levels(root->right);
    
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

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->right = f;

    d->right = g;

    e->left = h;

    cout << "PRE ORDER PRINTING IS : ";
    PreOrderDisplay(a);
    cout << endl;
    
    cout << "IN ORDER PRINTING IS : ";
    InOrderDisplay(a);
    cout << endl;
    
    cout << "POST ORDER PRINTING IS : ";
    PostOrderDisplay(a);
    cout << endl;
    
    cout << "SUM OF ELEMENTS ARE : " << sum(a) << endl;

    cout << "NUMBER OF NODES IN TREE IS : " << size(a) << endl;

    cout << "MAXIMUM VALUE OF NODE IS : " << maxx(a) << endl;

    cout << "HEIGHT OF TREE IS : " << height(a) << endl;

    cout << "LEVEL OF TREE IS : " << levels(a) << endl;

    cout << "DIAMETER (MAX LENGTH B/W TWO NODE) IS : " << dia(a) << endl;

    
}
