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
    void flatten(TreeNode* root) {
        // base case
        if (root==NULL) return NULL;

        // flatten both subtrees and append left then right
        flatten(root->left);
        flatten(root->right);

        if (root->left){
            TreeNode* temp=root->left;
            while (temp && temp->right){
                temp=temp->right;
            }
            temp->right = root->right;
            root->right=root->left;
            // left side should be null
            root->left = NULL;
        }
    }
};