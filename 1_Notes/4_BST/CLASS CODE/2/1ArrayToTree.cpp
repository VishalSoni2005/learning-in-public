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
    queue<node*>q;
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

        if(l != NULL) q.push(l);
        if(r != NULL) q.push(r);
        
        i += 2;
        j += 2;
    }
    return root;
}
int main() {
    vector<int> tree = {1, 2, -3, 4, 5, -6, 7, 8, INT_MIN, 9, 10, 11, INT_MIN, INT_MIN, INT_MIN};
    int n = tree.size();
    node* root = arrayToTree(tree, n);
    

}

// class Solution {
// public:
//     TreeNode* iop(TreeNode* root) {
//         TreeNode* pred = root->left;
//         while(root->right != NULL) pred = pred->right;
//         return pred;

//     }
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root == NULL) return NULL;
//         if(root->val == key) {
//             // CASE 1 (NO CHILD)
//             if(root->left == NULL and root->right == NULL) return NULL;
//             // CASE 2 (ONE CHILD)
//             if(root->left == NULL || root->right == NULL) {
//                 if(root->left != NULL) return root->left;
//                 else return root->right;
//             }
//             // CASE 3 (TWO CHILD)
//             if(root->left != NULL and root->right != NULL) (
//                 //  REPLACE THE ROOT WITH INORDER PERD OR INORDER SUCC
//                 //  HERE WE USE PREDECESSOR
//                 TreeNode* pred = iop(root);
//                 root->val = pred->val;
//                 root->left = deleteNode(root->left, pred->val);
//             )
//         }
//         //this is for leaf node
//         else if(key > root->val) root->right = deleteNode(root->right, key);
//         else root->left = deleteNode(root->left, key);

//         //node having one chile
//         return root;
//     }
// };