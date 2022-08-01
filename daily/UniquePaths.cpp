#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int p, q;
    vector<vector<int>> dp;
    int dfs(int i, int j){
        if (i==p || j==q) return 0;
        if (i==p-1 && j==q-1) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = dfs(i+1, j) + dfs(i, j+1);
    }
    int uniquePaths(int m, int n) {
        p=m; q=n;
        dp.resize(m, vector<int>(n, -1));

        return dfs(0, 0);
    }
};