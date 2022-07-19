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
        //already copied this node
        if (copied[node]) return copied[node]; 
        
        //copy the node val and neighbors
        Node* newNode = new Node();
        //save the node before visiting neighbors
        copied[node] = newNode;

        newNode->val = node->val;
        for (auto &i: node->neighbors){
            newNode->neighbors.push_back(cloneGraph(i));
        }

        return newNode;    
    }
};