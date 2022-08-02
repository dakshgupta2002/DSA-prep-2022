#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> coin;
    vector<int> dp;
    int ans;
    int pickCoin(int amount){
        if (amount==0) return dp[amount] = 0; //i found a possible combination
        if (dp[amount] != -2) return dp[amount];

        int minCoins = INT32_MAX;
        for (auto &i: coin){
            // pick this coin of value if possible
            int picked = amount>=i? pickCoin(amount-i): -1;
            if (picked!=-1) minCoins = min(minCoins, 1+picked);
        }
        return dp[amount] = minCoins==INT32_MAX? -1: minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        coin=coins;
        sort(coin.begin(), coin.end());
        ans=coins.size();
        dp.resize(amount+1, -2);

        pickCoin(amount);
        return dp[amount];
    }
};