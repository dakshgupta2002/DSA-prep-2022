#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowest_apple(int n, int i, int p, vector<vector<int>>& adjacency, vector<bool>& hasApple){
        int sum=0, no_apples=0; //count the children that dont have apples
        for (int c: adjacency[i]){
            if (c==p) continue; // prevent traversing to back parent 
            int have_to_travel = lowest_apple(n, c, i, adjacency, hasApple);

            if (have_to_travel==-1) no_apples++; //if the child has no apples
            else sum += 2+have_to_travel; //if child has apples, back and forth (2)
        }
        cout << "Checked on children: " << i << " " << sum << endl;
        //if all children are false, then no need to travel
        if (no_apples == adjacency[i].size()-1){ //reduce one for parent, children have no apples
            cout << "Stop Iteration " << i << " " << hasApple[i] << endl;
            if (hasApple[i]==false) return -1;
            else return 0;
        }
        cout << "____________________" << endl;
        return sum;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adjacency(n, vector<int>());
        adjacency[0].push_back(-1); //consider -1 to be the parent of 0

        for (int i = 0; i < edges.size(); i++){
            adjacency[edges[i][0]].push_back(edges[i][1]);
            adjacency[edges[i][1]].push_back(edges[i][0]);
        }
        return max(lowest_apple(n, 0, -1, adjacency, hasApple), 0);
    }
};