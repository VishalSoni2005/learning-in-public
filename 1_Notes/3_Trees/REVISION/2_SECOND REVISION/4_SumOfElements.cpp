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
node* vectorToTree(vector<int>& nums) {
    queue<node*>q;
    node* root = new node(nums[0]);
    q.push(root);

    int i = 1;
    int j = 2;

    while(q.size() > 0 && i < nums.size()) {
        node* temp = q.front();
        q.pop();
        node* l;
        node* r;

        if(nums[i] != INT_MIN) l = new node(nums[i]);
        else l = NULL;
        if(j != nums.size() and nums[j] != INT_MIN) r = new node(nums[j]);
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
int sum(node* root) {
    if(root == NULL) return 0;
    return root->val + sum(root->left) + sum(root->right);
}
int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    node* root = vectorToTree(nums);
    cout << sum(root);
}