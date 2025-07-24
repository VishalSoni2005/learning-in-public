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
class levelOrderPrinting{
public:

    int lvl(node* root) {
    if(!root) return 0;
        return 1 + max(lvl(root->left), lvl(root->right));
    }
    void lvlOrder(node* root, int curr, int level) {
        if(!root) return;
        if(curr == level) {
            cout << root->val << " ";
            // return; //MIND
        }
        lvlOrder(root->left, curr+1, level);
        lvlOrder(root->right, curr+1, level);
    }
    void levelsPrinting(node* root) {
        if(!root) return;
        int n = lvl(root);
        cout << "LEVEL WISE PRINTING : " << endl;
        for(int i=0; i<n; i++) {
            lvlOrder(root, 0, i);
            cout << endl;
        }
    }
};
class iterativePrinting{
public:
    void iterPRE(node* root) {
        cout << "PER ORDER : ";

        stack<node*> container;
        container.push(root);

        while (container.size()>0)
        {
            node* temp = container.top();
            cout << container.top()->val << " ";
            container.pop();
            if(temp->right) container.push(temp->right);
            if(temp->left) container.push(temp->left);
        }
        cout << endl;
    }
    void iterIN(node* root) {
        cout << "IN ORDER : ";

        stack<node*> container;
        node* curr = root;

        while(curr != NULL || !container.empty()) {
            while(curr != NULL) {
                container.push(curr);
                curr = curr->left;
            }

            curr = container.top();
            container.pop();
            cout << curr->val << " ";

            curr = curr->right;
        }
        cout << endl;
    }

    void iterPOST(node* root) {
        cout << "POST ORDER USING TWO STACK : ";

        if (!root) return;

        stack<node*> stack1, stack2;
        stack1.push(root);

        while (!stack1.empty()) {
            node* temp = stack1.top();
            stack1.pop();
            stack2.push(temp);

            if (temp->left) stack1.push(temp->left);
            if (temp->right) stack1.push(temp->right);
        }

        while (!stack2.empty()) {
            node* temp = stack2.top();
            stack2.pop();
            cout << temp->val << " ";
        }
        cout << endl;
    }

    void helper(node* root, vector<int>&v) {
        cout << "POST ORDER USING ONE STACK : ";

        stack<node*> container;
        container.push(root);

        while (container.size()>0)
        {
            node* temp = container.top();
            v.push_back(temp->val);
            container.pop();
            if(temp->left) container.push(temp->left);
            if(temp->right) container.push(temp->right);
        }
    }
};
node* construct(int arr[], int n) {

    queue<node*>container;
    node* root = new node(arr[0]);
    container.push(root);

    int i = 1;
    int j = 2;

    while(container.size() > 0 and i < n) {

        node* temp = container.front();
        container.pop();

        node* leftNode;
        node* rightNode;
        
        if(arr[i] != INT_MIN) leftNode = new node(arr[i]);
        else leftNode = NULL;
        if(i != n and arr[j] != INT_MIN) rightNode = new node(arr[j]);
        else rightNode = NULL;

        temp->left = leftNode;
        temp->right = rightNode;

        if(leftNode) container.push(leftNode);
        if(rightNode) container.push(rightNode);

        i += 2;
        j += 2;
    }
    return root;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9, 10};
    node* root = construct(arr, 13);

    levelOrderPrinting tree;
    tree.levelsPrinting(root);


    iterativePrinting Tree;
    Tree.iterPRE(root);
    Tree.iterIN(root);
    Tree.iterPOST(root);

    vector<int>v;
    Tree.helper(root, v);
    reverse(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) cout << v[i] << " ";
}