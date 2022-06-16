#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;

        if (target == 0) return nums.size(); 
        //means the complete array has to be removed x 

        int i=0;
        int curr = 0, max_len = 0;

        for (int j=0; j<nums.size(); j++){
            curr += nums[j]; //include everywhere j goes
            while (i<=j && curr > target){ 
                //while subarray is bigger, reduce it
                curr -= nums[i];
                i++;
            }
            //accept one solution of the subarray
            if (curr==target) max_len = max(max_len, j-i+1);
        }

        return max_len==0?-1:nums.size()-max_len;
    }
};
