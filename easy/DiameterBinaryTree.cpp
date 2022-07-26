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
    int dia = 0;
    int height(TreeNode* parent){
        if (parent==NULL) return -1;
        return 1+max(height(parent->left), height(parent->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root){
            dia = max(dia, height(root->left)+height(root->right));
            
            diameterOfBinaryTree(root->left);
            diameterOfBinaryTree(root->right);
        }
        
        return dia;
    }
};

class Solution2{
    int dia=0;

    int dum(TreeNode* root){
        if (root==NULL) return -1;

        int left = 1+dum(root->left);
        int right = 1+dum(root->right);

        dia = max(dia, left+right);
        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // save the height on left and right for each and recurse with max
        dum(root);
        return dia;
    }
};