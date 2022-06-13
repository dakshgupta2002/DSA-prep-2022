#include<bits/stdc++.h>
using namespace std;
#define ll long long 

class Solution {
public:
    // nums[i] - rev(nums[i]) = nums[j] - rev(nums[j])
    ll rev (ll x){
        ll res = 0;
        while (x>0){
            res*=10; res += x%10;
            x/=10;
        }
        return res;
    }

    int countNicePairs(vector<int>& nums) {        
        unordered_map<ll, int> mp;
        ll count=0;

        // the pairs of n - rev(n) are pairs*(pairs-1) / 2 
        // which is equal to sum of natural number from 1 to pairs
        //so instead of multiplying pairs*pairs-1 which goes to overflow 
        for(auto& num : nums) count = (count + mp[num - rev(num)]++) % 1000000007;
        return count;
    }
};