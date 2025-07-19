#include<bits/stdc++.h>
using namespace std;
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
  
   void find(Node* root, int& l, int& r, int pos) {
        if (!root)
            return;
        l = min(pos, l);
        r = max(pos, r);
        find(root->left, l, r, pos - 1);
        find(root->right, l, r, pos + 1);
        return;
    }

    vector<vector<int>> verticalOrder(Node *root) {
        // Your code here
        
        vector<vector<int>> ans;
        if (!root)
            return ans;

        int l = 0, r = 0;
        find(root, l, r, 0);

        int ls = abs(l);
        int rs = r + 1;

        vector<vector<int>> nnum(ls);
        vector<vector<int>> pnum(rs);

        queue<int> idx;
        queue<Node*> q;
        q.push(root);
        idx.push(0);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            int pos = idx.front();
            idx.pop(); 

            if (pos < 0) {
                nnum[abs(pos) - 1].push_back(temp->data);
            } 
            
            else {
                pnum[pos].push_back(temp->data);
            }

            if (temp->left) {
                idx.push(pos - 1);
                q.push(temp->left);
            }
            if (temp->right) {
                idx.push(pos + 1);
                q.push(temp->right);
            }
        }

        reverse(nnum.begin(), nnum.end());
        for (auto i : nnum)
            ans.push_back(i);
        for (auto i : pnum)
            ans.push_back(i);
        return ans;
        
    }
};