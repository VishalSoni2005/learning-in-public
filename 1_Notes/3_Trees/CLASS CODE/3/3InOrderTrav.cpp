#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int val;
    node* right;
    node* left;
    node(int val) {
        this->val = val;
        right = NULL;
        left = NULL;
    }
};
void BFS_printing(node* root) {
    queue<node*>q;
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
node* construct(int arr[], int n) {
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

        if(arr[i] != INT_MIN) l = new node(arr[i]);
        else l = NULL;
        if(j != n && arr[j] != INT_MIN) r = new node(arr[j]);
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
void preOrderIterative(node* root) {
    stack<node*> st;
    st.push(root);

    while(st.size() > 0) {
        node* temp = st.top();
        st.pop();
        if(temp->right != NULL) st.push(temp->right);
        cout << temp->val << " ";
        if(temp->left != NULL) st.push(temp->left); 
    }
    cout << endl;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9};
    node* root = construct(arr, 12);
    cout << "BFS_printing -> ";
    BFS_printing(root);

    cout << "Iterative printing -> ";
    preOrderIterative(root);
}