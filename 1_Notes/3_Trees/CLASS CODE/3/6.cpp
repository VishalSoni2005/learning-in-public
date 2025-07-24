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
int levels(node* root) {
    if(root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
void levelOrderPrinting(node* root, int curr, int lvl) {
    if(root == NULL) return ;
    if(curr == lvl) {
        cout << root->val << " ";
        return;
    }
    levelOrderPrinting(root->left, curr+1, lvl);
    levelOrderPrinting(root->right, curr+1, lvl);

}
void levelOrder(node* root) {
    cout << endl;
    int n = levels(root);
    for(int i = 1; i<=n; i++) {
        levelOrderPrinting(root, 1, i);
        cout << endl;
    }
}
int main() {
    vector<int> tree = {1, 2, -3, 4, 5, -6, 7, 8, INT_MIN, 9, 10, 11, INT_MIN, INT_MIN, INT_MIN};
    int n = tree.size();
    node* root = arrayToTree(tree, n);
    cout << "BFS printing is ; ";
    BFS_printing(root);
    cout << endl;

    cout << "Levels Wise Printing is : ";
    levelOrder(root);

    // cout << endl;

}
