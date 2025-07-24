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
        this->left = NULL;
        this->right = NULL;
        this->val = val;
    }
};
// void nlvl(node* root, int curr, int level) {
//     if(root == NULL) return;
//     if(curr == level) {
//         cout << root->val << " ";
//         return ;
//     }
//     nlvl(root->left, curr + 1, level);
//     nlvl(root->right, curr + 1, level);
// }

int levels(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
void printNthLvl(node *root, int curr, int lvl)
{
    if (root == NULL)
        return;
    if (curr == lvl)
    {
        cout << root->val << " ";
        return;
    }
    printNthLvl(root->left, curr + 1, lvl); // PRE ORDER TRAVERSAL
    printNthLvl(root->right, curr + 1, lvl);
    // PRE ORDER TRAVERSAL
}
void printNthLvlRev(node *root, int curr, int lvl)
{
    if (root == NULL)
        return;
    if (curr == lvl)
    {
        cout << root->val << " ";
        return;
    }
    printNthLvl(root->right, curr + 1, lvl); // First Right
    printNthLvl(root->left, curr + 1, lvl);  // Then Left
}
void levelOrder(node *root)
{
    int n = levels(root);
    for (int i = 1; i <= n; i++)
    {
        printNthLvl(root, 1, i);
        cout << endl;
    }
}
void levelOrderRev(node *root)
{
    int n = levels(root);
    for (int i = 1; i <= n; i++)
    {
        printNthLvlRev(root, 1, i);
        cout << endl;
    }
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

    cout << endl;
    cout << "Level Order Traversal (Left to Right)" << endl;
    levelOrder(a);
    cout << "Level Order Traversal (Right to Left)" << endl;
    levelOrderRev(a);
    cout << endl;
}