#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> res;
    vector<vector<int>> adjacency;
    vector<int> countLabels(int i, int p, string &labels){
        vector<int> freq(26);
        // cout << i << " has label " << labels[i]-'a' << endl;     
        for (auto c: adjacency[i]){
            if (c==p) continue;
            // cout << "Checks on the subtree children " << c << endl;;
            vector<int> temp = countLabels(c, i, labels);
            for (int i=0; i<26; i++) freq[i]+=temp[i];
        }
        // cout << "Contains " << freq[labels[i]-'a'] << " same chars " << endl << "__________________" << endl;
        freq[labels[i]-'a']++;
        res[i] = freq[labels[i]-'a'];
        return freq;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adjacency.resize(n);
        res.resize(n);
        adjacency[0].push_back(-1);
        for (int i = 0; i < edges.size(); ++i) {
            adjacency[edges[i][0]].push_back(edges[i][1]);
            adjacency[edges[i][1]].push_back(edges[i][0]);
        }
        countLabels(0, -1, labels);
        return res;
    }
};