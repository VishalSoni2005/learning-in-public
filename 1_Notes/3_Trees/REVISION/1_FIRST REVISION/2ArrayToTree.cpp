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
node* arrayToTree(vector<int> &v, int n) {
    queue<node*> q;
    node* root = new node(v[0]);
    q.push(root);

    int i =1; 
    int j = 2;
    while(q.size() > 0 && i < n) {
        node* temp = q.front();
        q.pop();
        node* l;
        node* r;

        if(v[i] != INT_MIN) l = new node(v[i]);
        else l = NULL;
        if(v[j] != INT_MIN) r = new node(v[j]);
        else r = NULL;

        temp->left = l;
        temp->right = r;

        if(l != NULL) q.push(l);
        if(r != NULL) q.push(r);

        i += 2;
        j += 2;
    }
    return root;
}
void display(node* root) {
    if(root == NULL) return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}
int main() {
    vector<int> v = {6, 4, 9, 8, INT_MIN, 12, INT_MIN, INT_MIN, 5, 7, INT_MIN};
    int n = v.size();
    node* root = arrayToTree(v, n);
    cout << "Pre Order Traversal is : ";
    display(root);
}