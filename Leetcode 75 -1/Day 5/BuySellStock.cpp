#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT32_MAX, profit=0;
        for (auto &i: prices){
            if (i<buy) buy=i;
            else profit=max(profit, i-buy);
        }
        return profit;
    }
};