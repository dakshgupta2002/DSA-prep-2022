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
//O(n) space O(n) time
class Solution1 {
public:
    void inorder(TreeNode* root, vector<int> &sorted){
        if (root == NULL) return;
        inorder(root->left, sorted);
        sorted.push_back(root->val);
        inorder(root->right, sorted);        
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> sorted;
        inorder(root, sorted);
        return sorted[k-1];
    }
};

//O(max(H, k)) maibi and O(k) space for k ele max
class Solution {
public:
    stack<TreeNode*> st;

    int kthSmallest(TreeNode* root, int k) {
        while (true){
            while (root != NULL){
                st.push(root);
                root=root->left;
            }

            TreeNode* least=st.top(); 
            st.pop();

            k--; //because i visited the smallest element 
            if (k==0) return least->val; //hence answer 

            //now visit the right side 
            root = least->right;
        }
    }
};


