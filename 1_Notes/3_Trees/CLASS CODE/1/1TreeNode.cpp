#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;
    node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void display(node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}
int sum(node *root)
{
    if (root == NULL)
        return 0;
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return root->val + leftSum + rightSum;
}
int product(node *root)
{
    if (root == NULL)
        return 1;
    return root->val * product(root->left) * product(root->right);
}
int size(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}
int maxInTree(node *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->val, max(maxInTree(root->left), maxInTree(root->right)));
}
int minInTree(node *root)
{
    if (root == NULL)
        return INT_MAX;
    return min(root->val, min(minInTree(root->left), minInTree(root->right)));
}
int levels(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
int main()
{
    node *a = new node(1);
    node *b = new node(2);
    node *c = new node(3);
    node *d = new node(4);
    node *e = new node(5);
    node *f = new node(6);
    node *g = new node(7);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

    // for(int i=1; i<=3; i++) {
    //     cout << a->val << " ";
    //     a = a->left;
    // }
    cout << "Tree is : ";
    display(a);
    cout << endl;
    cout << "Sum of Elements of tree is : " << sum(a) << endl;
    cout << "Product of elements of tree is : " << product(a) << endl;
    cout << "Size of tree is : " << size(a) << endl;
    cout << "Max in Tree is: " << maxInTree(a) << endl;
    cout << "Min in Tree is : " << minInTree(a) << endl;
    cout << "Levels are : " << levels(a) << endl;
    cout << "Height of Tree is : " << levels(a) - 1 << endl;
}