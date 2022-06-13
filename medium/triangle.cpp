#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int travel(vector<vector<int>> &triangle, vector<vector<int>> &dp, int i, int j){
        if (i==triangle.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        //calculate the minimum cost to reach the end 
        return dp[i][j] = triangle[i][j] + min(
            travel(triangle, dp, i+1, j),
            travel(triangle, dp, i+1, j+1)
        );
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        return travel(triangle, dp, 0, 0);
    }
};