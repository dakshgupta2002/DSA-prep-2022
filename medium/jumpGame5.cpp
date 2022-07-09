#include<bits/stdc++.h>
using namespace std;
#define INT__MIN -1000000000

//calculate the score from each index and store in memo
//O(N*k) solution since calculate every index in O(k) time 
class Solution1 {
public:
    int jump(vector<int>& nums, int k, int i, vector<int>& dp){
        if (i>=nums.size()) return INT__MIN; //pruning
        if (i==nums.size()-1) return nums[i]; //base case

        if (dp[i] != INT__MIN) return dp[i]; //cache

        //calculate the score of the index
        int max_score = INT__MIN;
        for (int j=i+1; j<=i+k; j++){
            max_score = max(max_score, jump(nums, k, j, dp));
        }   

        return dp[i] = nums[i] + max_score;
    }

    int maxResult(vector<int>& nums, int k) {
        
        vector<int> dp(nums.size(), INT__MIN);
        return jump(nums, k, 0, dp);
    }
};