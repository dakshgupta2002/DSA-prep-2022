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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        vector<TreeNode*> level;
        level={root};

        while (!level.empty()){
            vector<TreeNode*> newLevel;
            for (auto &i: level){
                if (i->left) newLevel.push_back(i->left);
                if (i->right) newLevel.push_back(i->right);
            }
            res.push_back(level[level.size()-1]->val);
            level = newLevel;
        }
        return res;        
    }
};