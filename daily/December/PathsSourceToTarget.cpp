#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void dfs(int i, vector<vector<int>>& graph, vector<int> path){
        path.push_back(i); // add the current node to my walking path

        if (i==graph.size()-1){ //if i have reached destination
            res.push_back(path);
            return;
        }
        // travel to the neighbor node and explore all possible paths
        for (int j=0; j<graph[i].size(); j++){
            dfs(graph[i][j], graph, path);
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0, graph);
        return res;
    }
};