#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int res=0;
        vector<int> ans;
        for (auto &i: nums) res+=i;

        for (auto q: queries){
            if(nums[q[1]]%2==0) res-=nums[q[1]];
            nums[q[1]]+=q[0];
            if (nums[q[1]]%2==0) res+=nums[q[1]];

            ans.push_back(res);
        }   
        return ans;
    }
};