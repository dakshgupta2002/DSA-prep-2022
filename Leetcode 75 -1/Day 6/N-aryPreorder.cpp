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

class Recursive {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        if (root==NULL) return res;

        res.push_back(root->val);
        for (int i=0; i<root->children.size(); i++){
            preorder(root->children[i]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> s;
        s.push(root);
            
        while (s.size()){
            res.push_back(s.top()->val);
            Node* parent = s.top();
            s.pop();

            for (int i=parent->children.size()-1; i>=0; i--){
                s.push(parent->children[i]);
            }
        }
        return res;
    }
};