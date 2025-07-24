#include<iostream>
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
int lvl(node* root){
    if(root == NULL) return 0;
    return 1 + max(lvl(root->left) , lvl(root->right));
}
void nlvl(node* root, int curr, int level) {
    if(root == NULL) return;
    if(curr == level) {
        cout << root->val << " ";
        return ;
    }
    nlvl(root->left, curr + 1, level);
    nlvl(root->right, curr + 1, level);

}  
int main() {
    node* a = new node(1);
    node* b = new node(2);
    node* c = new node(3);
    node* d = new node(4);
    node* e = new node(5);
    node* f = new node(6);
    node* g = new node(7);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

    int j = lvl(a);
    for(int i=1; i<=j; i++) {
        nlvl(a, 1, i);
        cout << endl;
    }
    
}