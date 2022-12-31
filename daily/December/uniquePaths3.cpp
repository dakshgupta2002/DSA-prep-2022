#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int count){
        //losing condition: out of bounds, obstacle or visited
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 0;
        if (grid[i][j]==-1 || grid[i][j]==3 || grid[i][j]==1) return 0;
        //winning condition: final node and visited all nodes
        if (grid[i][j]==2){
          cout << count << endl;
          if (count==0) return 1;
          return 0;
        }
        //travelling condition
        grid[i][j]=3;
        int ans = dfs(grid, i+1, j, count-1)
            +dfs(grid, i-1, j, count-1)
            +dfs(grid, i, j+1, count-1)
            +dfs(grid, i, j-1, count-1);
        grid[i][j]=0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        // while traversing on a path, keep a track of the nodes 
        int count=0, x, y;
        for (int i=0; i<grid.size(); i++) for (int j=0; j<grid[i].size(); j++){
          if (grid[i][j]==1) {x=i; y=j;}
          if (grid[i][j]==0) count++;
        }
        return dfs(grid, x-1, y, count)
            +dfs(grid, x+1, y, count)
            +dfs(grid, x, y-1, count)
            +dfs(grid, x, y+1, count);
    }
};