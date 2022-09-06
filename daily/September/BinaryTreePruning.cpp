#include <bits/stdc++.h>
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
    bool consist(TreeNode* root){
        if (root==NULL) return false;
        bool left = consist(root->left);
        bool right = consist(root->right);
        
        if (!left) root->left=NULL;
        if (!right) root->right=NULL;

        return root->val || right || left;

    }

    TreeNode* pruneTree(TreeNode* root) {
        if (!consist(root)) root=NULL;
        return root;
    }
};