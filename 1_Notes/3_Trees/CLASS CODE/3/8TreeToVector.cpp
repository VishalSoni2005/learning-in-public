#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
node* arrayToTree(vector<int>&v, int n) {
    queue<node*> q;
    node* root = new node(v[0]);
    q.push(root);

    int i = 1; 
    int j = 2;

    while(q.size() > 0 and i < n) {
        node* temp = q.front();
        q.pop();
        node* l;
        node* r;

        if(v[i] != INT_MIN) l = new node(v[i]);
        else l = NULL;
        if(j != n and v[j] != INT_MIN) r = new node(v[j]);
        else r = NULL;

        temp->left = l;
        temp->right = r;

        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);

        i += 2;
        j += 2;
    }
    return root;
}
void BFS_printing(node* root) {
    queue<node*> q;
    q.push(root);
    while(q.size() > 0) {
        node* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}
void helper(node* root, vector<int>& ans) {
        if(root == NULL ) return ;
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
}

void inOrderPrint(node* root) {
    if(root == NULL) return ;
    inOrderPrint(root->left);
    cout << root->val << " ";
    inOrderPrint(root->right);
}
int main() {
    vector<int> tree = {5, 1, 4, INT_MIN, INT_MIN, 3, 6};
    int n = tree.size();
    node* root = arrayToTree(tree, n);
    cout << "BFS printing is : ";
    BFS_printing(root);
    cout << endl;   

    cout << "In order Traversal is : ";
    inOrderPrint(root);
    cout << endl;

    vector<int>v;
    helper(root, v);

    cout << "Vector Printing : " ;
    for(int i = 0; i< v.size(); i++) cout << v[i] << " ";
        


}