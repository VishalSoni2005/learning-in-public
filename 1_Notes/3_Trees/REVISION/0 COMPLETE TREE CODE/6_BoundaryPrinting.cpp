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
class BoundaryPrinting{
public:
    void leftboundaryPrinting(node* root) {
        if(root == NULL) return ;
        if(root->left == NULL and root->right == NULL) return;
        cout << root->val << " ";
        leftboundaryPrinting(root->left);
        if(root->left == NULL) leftboundaryPrinting(root->right);
    }
    void printLeaf(node* root) {
        if(!root) return ; 
        if(root->left == NULL and root->right == NULL) cout << root->val << " ";
        printLeaf(root->left);
        printLeaf(root->right);
    }
    void rightboundaryPrinting(node* root) {
        if(root == NULL ) return ;
        if(root->left == NULL && root->right == NULL) return;
        rightboundaryPrinting(root->right);
        if(root->right == NULL) rightboundaryPrinting(root->left);
        cout << root->val << " ";
    }
};
void AntiClockWise(node* root) {
    //  FIRST PART
    // queue<node*>q;
    // q.push(root);
    // while(q.size() > 0) {
    //     node* temp = q.front();
    //     q.pop();
    //     cout << temp->val << " ";
    //     if(temp->left) q.push(temp->left);
    //     if(temp->left->left == NULL) break;
    // }
    // ABOVE CODE WAS NOT PRODUCTION READY

    BoundaryPrinting tree;
    tree.leftboundaryPrinting(root);

    //  SECOND PART  LEAF ROOT
    tree.printLeaf(root);

    //  THIRD PART  RIGHT
    tree.rightboundaryPrinting(root->right);

}

int main() {
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9, 10};
    node* root = construct(arr, 13);

    // levelOrderPrinting tree;
    // tree.levelsPrinting(root);

    AntiClockWise(root);
   
}