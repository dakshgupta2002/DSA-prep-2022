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
    int i=0, j;
    TreeNode* res;
    void inorder(TreeNode* root){
        if (root==NULL) return;
        
        inorder(root->left);
        i++;
        if (i==j) {
            res = root;
            return;
        }
        inorder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        j=k;
        inorder(root);
        return 
    }
};