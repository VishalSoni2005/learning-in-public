#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->left = NULL;
        this->right = NULL;
        this->val = val;
    }
};

void LevelOrderTraversalUsingQueue(node* root) {
    queue<node*>q;
    q.push(root);
    while(q.size() > 0) {
        node* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
    cout << endl;
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

    LevelOrderTraversalUsingQueue(a);
}