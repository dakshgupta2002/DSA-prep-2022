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
    bool balanced = true;
    int dum(TreeNode* root){
        if (root==NULL) return -1;
        
        int l=dum(root->left);
        int r=dum(root->right);

        if (abs(l-r) > 1) balanced=false;
        return 1+ max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        dum(root);
        return balanced;
    }
};