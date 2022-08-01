#include <bits/stdc++.h>
using namespace std;
    
class Solution {
public:
    vector<int> dp;
    int choose(int i, vector<int> &nums){
        if (i==nums.size()) return 0;
        if (dp[i] != -1) return dp[i];

        return dp[i] = max(nums[i] + choose(i+2, nums), choose(i+1, nums));
    }

    int rob(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return choose(0, nums);
    }
};