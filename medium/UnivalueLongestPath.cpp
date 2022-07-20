#include<bits/stdc++.h>
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
    int longestUnivaluePath(TreeNode* root) {
        if (root==NULL) return 0;
        int ans=0;
        if (root->left && root->left->val == root->val) {
            ans += 1+longestUnivaluePath(root->left);
        }
        if (root->right && root->right->val == root->val) {
            ans += 1+longestUnivaluePath(root->right);
        }

        return max({ ans, longestUnivaluePath(root->left), longestUnivaluePath(root->right)});
    }
};