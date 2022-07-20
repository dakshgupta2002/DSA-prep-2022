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
    map<TreeNode*, int> heights;

    int height(TreeNode* parent){
        if (parent==NULL) return 0;
        if (heights.find(parent)!=heights.end()) return heights[parent];

        return heights[parent] = 1+max(height(parent->left), height(parent->right));
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
    int diameterOfBinaryTree(TreeNode* root) {
        
    }
};