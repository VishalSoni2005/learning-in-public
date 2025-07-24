#include<bits/stdc++.h>
using namespace std;
class node{
public:
    char val;
    node* left;
    node* right;
    node(char val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
node* arrayToTree(char arr[], int n) {  //CONSTRUCTED A TREE USING LEVEL ORDER TRAVERSAL 
    queue<node*> q;
    node* root = new node(arr[0]);
    q.push(root);

    int i = 1; 
    int j = 2;
    while(q.size() > 0 && i < n) {
        node* temp = q.front();
        q.pop();
        node* l;
        node* r;

        if(arr[i] != '#') l = new node(arr[i]);
        else l = NULL;
        if(j != n && arr[j] != '#') r = new node(arr[j]);
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
void BFS_printing(node* root) { // LEVEL ORDER PRINTING
    queue<node*> q;
    q.push(root);
    while(q.size() > 0) {
        node* temp = q.front();
        q.pop();
        cout << temp->val << " ";

        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
    cout << endl;
}

void preOrderPrint(node* root ) {
    if(root == NULL) return ;
    cout << root->val << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}
void inOrderPrint(node* root ){
    if(root == NULL) return ;
    inOrderPrint(root->left);
    cout << root->val << " ";
    inOrderPrint(root->right);
}
void postOrderPrint(node * root) {
    if(root == NULL) return ;
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    cout << root->val << " ";
}

int main() {
    char arr[] = {'a', 'b', 'c', 'x', 'y', 'z', 'w' ,'#', 'p', 'q', 'r', 's', 't', 'u', '#', 'm', 'n', '#', 'e', '#', '#', 'l', 'm', 'n', 'o', 't', 'x', 'x'};
    node* root = arrayToTree(arr, 28);
    // cout << "Array To Tree ->" ;
    // BFS_printing(root);
    cout << "Pre Order Traversal Printing is : ";
    preOrderPrint(root);
    cout << endl;
    cout << "IN Order Traversal Printing is : ";
    inOrderPrint(root);
    cout << endl;
    cout << "Post Order Traversal Printing is : ";
    postOrderPrint(root);
    cout << endl;

}