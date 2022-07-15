#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> num;
    vector<int> visited;
    int subsetsFormed=0;
    int target=0;

    void createSubset(int curr, int ind){
        if (curr == target){
            subsetsFormed+=1;
            createSubset(0, 0);
        }
        if (ind == num.size()){
            return;
        }

        

    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%k != 0) return false;
        target = sum/k;

        for (auto &i:nums) if (i>target) return false;

        sort(nums.begin(), nums.end());

        num=nums;
        visited.resize(nums.size(), 0);
        createSubset(0, 0);

        if (subsetsFormed == k) return true;
        return false;
    }
};