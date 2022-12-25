#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for (int i=1; i<=nums.size(); i++) nums[i]+=nums[i-1];
        vector<int> res(queries.size());

        for (int i=0; i<=queries.size(); i++){
            int ans = 0;
            //binary search for the maximum elements 
            int lo=0, hi=nums.size()-1;
            while (lo <= hi){
                int mid = lo + (hi-lo)/2;
                if (nums[mid] <= queries[i]){
                    ans = mid+1;
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }
            res[i] = ans;
        }
        return res;
    }
};