#include <bits/stdc++.h>
using namespace std;
#define INT_MAX 100000000

//O(n^m) Time
class Solution{
public:
    int paint(vector<int> &houses, vector<vector<int>> &cost, int target, int i, int prev_col, vector<vector<vector<int>>>& dp){

        if (i == houses.size() && target == 1) return 0;
        if (target < 1 || i == houses.size()) return INT_MAX;

        if (dp[i][prev_col][target] != -1) return dp[i][prev_col][target];

        int min_cost = INT_MAX;
        if (houses[i] != 0){
            if (i>0 && houses[i] != prev_col) 
                min_cost = paint(houses, cost, target-1, i + 1, houses[i], dp);
            else 
                min_cost = paint(houses, cost, target, i + 1, houses[i], dp);
        }

        else{
            // choose from all colors which to choose for this house
            for (int j = 0; j < cost[0].size(); j++){
                if (i>0 && j+1 != prev_col)
                    min_cost = min(min_cost, cost[i][j]+paint(houses, cost, target-1, i + 1, j+1, dp));
                else
                    min_cost = min(min_cost, cost[i][j]+paint(houses, cost, target, i + 1, j+1, dp));
            }
        }
        return dp[i][prev_col][target] = min_cost;
    }

    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target){

        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(m+1, -1)));

        int res = paint(houses, cost, target, 0, 0, dp);
        if (res == INT_MAX) return -1;
        return res;
    }
};

