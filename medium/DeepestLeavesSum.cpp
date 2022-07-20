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

class DFS {
public:
    int ans=0, h=0;
    int depth(TreeNode* root){
        if (root==NULL) return 0;
        return 1+max(depth(root->left), depth(root->right));
    }

    void LeafSum(TreeNode* parent, int l){
        if (h==l) ans+=parent->val;
        if (parent->left) LeafSum(parent->left, l+1);
        if (parent->right) LeafSum(parent->right, l+1);
    }

    int deepestLeavesSum(TreeNode* root) {
        h = depth(root);
        LeafSum(root, 1);
        return ans;
    }
};

class BFS {
public:
    int deepestLeavesSum(TreeNode* root) {
        int ans=0;
        queue<TreeNode*> level;
        level.push(root);

        while (!level.empty()){
            ans=0;
            int nodes = level.size();

            while (nodes--) {
                ans+=level.front()->val;
                if (level.front()->left) level.push(level.front()->left);
                if (level.front()->right) level.push(level.front()->right);
                level.pop();
            }
        }
        return ans;
    }
};