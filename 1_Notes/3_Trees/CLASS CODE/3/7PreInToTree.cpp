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
node* build(vector<int>& pre, int prelo, int prehi, vector<int>& in, int inlo, int inhi) {
    if(prelo > prehi) return NULL;
    node* root = new node(pre[prelo]);
    if(prelo == prehi) return root;
    int i = inlo;
    while(i <= inhi) {
        if(in[i] == pre[prelo]) break;
        i++;
    }
    int leftCount = i - inlo;
    int rightCount = inhi - i;
    root->left = build(pre, prelo + 1, prelo + leftCount , in, inlo ,i-1 );
    root->right = build(pre, prelo + leftCount + 1, prehi, in, i + 1 , inhi);
    return root;

}
node* buildTree(vector<int>& pre, vector<int>& in) {
    int n = pre.size();
    node* root = build(pre, 0, n-1, in, 0, n-1);
}
int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, INT_MIN, 9, 10, 11, INT_MIN, INT_MIN, INT_MIN};
    vector<int> pre = {1, 2, 4, 8, INT_MIN, 5, 9, 10, 3, 6, 11, INT_MIN, 7, INT_MIN, INT_MIN};
    vector<int> in  = {8, 4, INT_MIN, 2, 9, 5, 10, 1, 11, 6, INT_MIN, 3, INT_MIN, 7, INT_MIN};
    node* root = buildTree(pre, in);

    cout << "Level Order Printing is : " << endl;
    levelOrder(root);
}



















// class Solution {
// public:
//     long long maxx(TreeNode* root) {
//         if(root == NULL) return LLONG_MIN;
//         return max((long long)(root->val), max(maxx(root->left), maxx(root->right)));
//     }
//     long long minn(TreeNode* root) {
//         if(root == NULL) return LLONG_MAX;
//         return min((long long)(root->val), min(minn(root->left), minn(root->right)));
//     }
//     bool isValidBST(TreeNode* root) {
//         if(root == NULL) return true;
//         else if(root->val <= maxx(root->left)) return false;
//         else if(root->val >= minn(root->right)) return false;
//         return isValidBST(root->left) && isValidBST(root->right);
//     }
// };