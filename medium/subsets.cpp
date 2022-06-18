#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(vector<vector<int>> &res, vector<int> temp, vector<int> &nums, int i){
        if (i==nums.size()){
            res.push_back(temp);
            return res;
        }
        generate(res, temp, nums, i+1);
        temp.push_back(nums[i]);
        generate(res, temp, nums, i+1);

        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // include ith or dont include `
        vector<vector<int>> res;
        return generate(res, {}, nums, 0);

    }
};