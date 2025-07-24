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
node* construct(vector<int>&arr){
    queue<node*> q;
    node* root = new node(arr[0]);
    q.push(root);

    int i=1;
    int j=2;

    while(q.size() > 0 and i < arr.size()) {
        node* temp = q.front();
        q.pop();

        node* leftNode;
        node* rightNode;

        if(arr[i] != INT_MIN) leftNode = new node(arr[i]);
        else leftNode = NULL;
        if(i != arr.size() and arr[j] != INT_MIN) rightNode = new node(arr[j]);
        else rightNode = NULL;

        temp->left = leftNode;
        temp->right = rightNode;

        if(leftNode) q.push(leftNode);
        if(rightNode) q.push(rightNode);

        i += 2;
        j += 2;
    }
    return root;
}

void BFS_Print(node* root) {
    queue<node*>q;
    q.push(root);

    while(q.size() > 0) {
        node* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    cout << endl;
    return ;
}

int main() {
    vector<int>arr = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9, 10};
    node* root = construct(arr);
    BFS_Print(root);
}