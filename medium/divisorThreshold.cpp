#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1, hi=1000001; //max value of a number is 1e6
        int minDivider = 1;

        while (lo<=hi){
            int mid = lo + (hi-lo)/2;

            int sum=0; 
            for (int i=0; i<nums.size(); i++){
                sum+=nums[i]/mid;
                sum+=nums[i]%mid == 0? 0 : 1;
            }

            if (sum > threshold){
                lo = mid+1;
            }
            else{
                minDivider = mid; 
                //this mid satisfies my constaint, save it
                // move on to find smaller diviser
                hi = mid-1;
            }
        }

        return minDivider;
    }
};