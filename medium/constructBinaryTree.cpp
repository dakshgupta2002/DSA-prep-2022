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
    unordered_map<int, int> indexes;
    vector<int> pre, in;

    TreeNode* breakArray(int preS, int inS, int inE){
        if (inS>inE || preS>=pre.size()) return NULL;

        TreeNode* child = new TreeNode();
        child->val = pre[preS];

        int index=indexes[pre[preS]];

        child->left = breakArray(preS+1, inS, index-1);
        child->right = breakArray(preS+index-inS+1, index+1, inE);

        return child;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0; i<inorder.size(); i++) indexes[inorder[i]] = i;
        pre=preorder; in=inorder;

        TreeNode* root=NULL;
        root = breakArray(0,0,inorder.size()-1);
        return root;
    }
};