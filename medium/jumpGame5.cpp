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


//to optimize the top-down approach, use bottom-up app
//while going from bottom to up, store the scores in a max-heap
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if (nums.size()==1) return nums[nums.size()-1];

        priority_queue<pair<int,int>, vector<pair<int,int>>> scores;
        scores.push({ nums[nums.size()-1], nums.size()-1});

        for (int i=nums.size()-2; i>=0; i--){
            while (scores.top().second > i+k) scores.pop();

            if (i==0) break;
            else scores.push({nums[i]+scores.top().first, i});
        }
        return nums[0]+scores.top().first;
    }
};