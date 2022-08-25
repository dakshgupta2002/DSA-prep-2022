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
    int ans = 0;
    void findGood(TreeNode* root, int max){
        if (root==NULL) return;
        if (root->val > max){
            ans++;
            max = root->val;
        }
        findGood(root->left, max);
        findGood(root->right, max);
    }

    int goodNodes(TreeNode* root) {
        findGood(root, INT32_MIN);
        return ans;
    }
};