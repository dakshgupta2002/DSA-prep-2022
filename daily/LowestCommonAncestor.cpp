#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool contains(TreeNode* parent, TreeNode* child){
        if (parent==NULL) return false;
        return parent==child || contains(parent->left, child) || contains(parent->right, child);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL) return NULL;
        if (root == p || root == q) return root;

        int p_on_left=contains(root->left, p), q_on_left=contains(root->left, q);

        if (p_on_left==q_on_left && p_on_left==1) return lowestCommonAncestor(root->left, p, q);
        else if (p_on_left==q_on_left && p_on_left==0) return lowestCommonAncestor(root->right, p, q);
        return root;
    }

};