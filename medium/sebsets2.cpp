#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(vector<vector<int>> &res, vector<int> temp, vector<int> &nums, int i){
        if (i==nums.size()){
            res.push_back(temp);
            return res;
        }

        // same numbers count 
        int count = 0;
        while (i+count < nums.size() && nums[i+count]==nums[i])count++;
        for (int j=0; j<count; j++){
            temp.push_back(nums[i]);
            generate(res, temp, nums, i+count);
        }

        return res;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // include ith or dont include `
        vector<vector<int>> res;
        return generate(res, {}, nums, 0);

    }
};