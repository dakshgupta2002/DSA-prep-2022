#include<bits/stdc++.h>
using namespace std;

//O(n^2)
//2650ms
class TopDown {
public:
    vector<int> dp;
    vector<int> num;

    bool canReach(int ind){
        if (ind >= num.size()) return false;
        if (ind == num.size()-1) return true;

        if (dp[ind] != -1) return dp[ind];

        for (int j=ind+1; j<min((int)num.size(), ind+num[ind]+1); j++){
            if (canReach(j)) return dp[ind] = true;
        }
        return dp[ind] = false;
    }

    bool canJump(vector<int>& nums) {
        num=nums;
        dp.resize(nums.size(), -1);
        
        return canReach(0);
    }
};

//O(n^2)
//2100ms
class BottomUp {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[dp.size()-1] = true;
        for (int i=nums.size()-2; i>=0; i--){
            for (int j=i+1; j<min((int)nums.size(), i+nums[i]+1); j++){
                dp[i] = dp[i] || dp[j];
                if (dp[i]) break;
            }
        }
        return dp[0];
    }
};

//O(n)
//93ms
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size()-1;

        for (int i=nums.size()-2; i>=0; i--){
            if (i+nums[i]+1 >= last) last=i;
        }

        return last == 0;
    }
};