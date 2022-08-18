#include<bits/stdc++.h>
using namespace std;

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
    int ans = 0;
    int itr(TreeNode* root){
        if (root==NULL) return 0;

        int subtree_l = itr(root->left);
        int subtree_r = itr(root->right);
        int left = root->left && root->left->val == root->val? 1+subtree_l: 0;
        int right = root->right && root->right->val == root->val? 1+subtree_r: 0;

        ans = max(ans, left+right);
        return max(left, right);
    }

    int longestUnivaluePath(TreeNode* root) {
        itr(root);
        return ans;
    }
};