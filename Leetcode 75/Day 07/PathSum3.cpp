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
    int ans = 0;
    int target;

    void travel (TreeNode* root, int sum){
        if (root=NULL) return;
        if (sum==target) ans++;
    }
        
    int pathSum(TreeNode* root, int targetSum) {
        target=targetSum;
    }
};