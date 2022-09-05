#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> lvls;
        vector<vector<int>> res;

        if (root) lvls.push(root);

        while (lvls.size()){
            int sz=lvls.size();
            vector<int> temp;
            while (sz--){
                temp.push_back(lvls.front()->val);
                for (auto &c: lvls.top()->children){
                    lvls.push(c);
                }
                lvls.pop();
            }
            res.push_back(temp);
        }

        return res;
    }
};