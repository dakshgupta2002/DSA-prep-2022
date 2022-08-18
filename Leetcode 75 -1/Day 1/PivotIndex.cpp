#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int runningSum=0;

        for (int i=0; i<nums.size(); i++){
            if (runningSum == totalSum - runningSum - nums[i]) return i;
            runningSum += nums[i];
        }              
        return -1;
    }
};