#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        if (i<0 || j<0 || i>=grid.size() || j>=grid[i].size()) return 0;
        if (grid[i][j]==0) return 0;

        grid[i][j] = 0;
        //dfs on this node 
        return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j)+ dfs(grid, i, j+1)+ dfs(grid, i, j-1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;

        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[i].size(); j++){
                //call dfs and find the area of the island
                area = max(area, dfs(grid, i, j));
            }
        }    

        return area;
    }
};