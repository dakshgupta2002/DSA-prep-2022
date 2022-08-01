#include <bits/stdc++.h>
using namespace std;
    
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        if (n==2) return max(nums[0], nums[1]);

        int b = nums[n-1], a = max(nums[n-1], nums[n-2]);
        
        for (int i=n-3; i>=0; i--){
            int c = max(nums[i]+b, a);
            b=a;
            a=c;
        }
        return a;
    }
};