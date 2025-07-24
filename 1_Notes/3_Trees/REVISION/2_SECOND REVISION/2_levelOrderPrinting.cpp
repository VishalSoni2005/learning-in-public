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

int level(node* root) {
    if(root == NULL) return 0;
    return 1 + max(level(root->left), level(root->right));
}

void printing(node* root, int curr, int lvl) {
    if(root == NULL) return;
    if(curr == lvl) {
        cout << root->val << " ";
        return;
    }
    printing(root->left, curr+1, lvl);
    printing(root->right, curr+1, lvl);
}

void levelOrder(node* root) {
    int lvl = level(root);
    for(int i=1; i<=lvl; i++) {
        printing(root, 1, i);
        cout << endl;
    }
}

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
int main() {
    vector<int> nums = {1, -1, 6, -4, INT_MIN, INT_MIN, 7, INT_MIN, -2, 5, INT_MIN};
    node* root = vectorToTree(nums);
    levelOrder(root);
}