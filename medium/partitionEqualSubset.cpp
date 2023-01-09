#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int s;
    vector<vector<int>> dp;
    bool includes(int i, vector<int> &nums, int r){
        if (r==s/2) return true;
        if (r>s/2 || i>=nums.size()) return false;
        
        if (dp[i][r] != -1) return dp[i][r];

        return dp[i][r] = includes(i+1, nums, r) || includes(i+1, nums, r+nums[i]);
    }
    bool canPartition(vector<int>& nums) {  
        s = accumulate(nums.begin(), nums.end(), 0);
        if (s%2 == 1) return false;

        dp.resize(nums.size(), vector<int>(20001, -1));
        return includes(0, nums, 0);
    }
};