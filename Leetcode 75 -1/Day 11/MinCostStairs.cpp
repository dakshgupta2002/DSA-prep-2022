#include <bits/stdc++.h>
using namespace std;

class TopDown {
public:
    vector<int> dp;
    int minCost(vector<int> &cost, int i){
        if (i>=cost.size()) return 0;
        if (dp[i]!=-1) return dp[i];
        return dp[i] = cost[i] + min(minCost(cost, i+1), minCost(cost, i+2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size(), -1);
        return min(minCost(cost, 0), minCost(cost, 1));
    }
};

class BottomUp {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+2, 0);

        for (int i=cost.size()-1; i>=0; i--){
            dp[i]=cost[i]+min(dp[i+1], dp[i+2]);
        }

        return min(dp[0], dp[1]);
    }
};