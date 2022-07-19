#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    map<Node*, Node*> copied;

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        if (copied[node]) return copied[node]; //already copied this node
        
        Node* newNode = new Node();
        copied[node] = newNode; //save the node before visiting neighbors

        newNode->val = node->val;
        for (auto &i: node->neighbors){
            newNode->neighbors.push_back(cloneGraph(i));
        }

        return newNode;    
    }
};