#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        prefix[0]=1;
        int sum=0, ans=0;

        for (int i=0; i<nums.size(); i++){
            sum+=nums[i];
            ans+=prefix[sum-k];
            prefix[sum]++;
        }
        return ans;
    }
};