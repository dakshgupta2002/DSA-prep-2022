#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        if (root) s.push(root);
        //post order: left right root
        //traverse: root right left and reverse
        while (s.size()>0){
            TreeNode* p=s.top();
            res.push_back(p->val);
            s.pop();

            if (p->left) s.push(p->left);
            if (p->right) s.push(p->right);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};