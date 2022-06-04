#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        // teo pointer solution 
        sort(nums.begin(), nums.end());
        if (nums.size()<3) return (res);
        if (nums[0]>0) return (res);

        int i=0; 
        while (i<nums.size()){
            // cout << nums[i] << endl;
            if (nums[i] > 0) break;//this +ve next also +ve
            if (i>0 && nums[i]==nums[i-1]){ //prev num same, same triplet
                i++; continue;
            }

            int j=i+1, k=nums.size()-1;
            while (j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if (sum < 0){
                    j++;
                }else if (sum > 0){
                    k--;
                }else{
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while (j<k && nums[j]==nums[j-1]) j++;
                    while (k>j && nums[k]==nums[k+1]) k--;
                    // cout << "j" << j << "k" << k << endl;
                }
            }
            i++;
        }

        return res;
    }
};


//first duplicate prevention by skipping same first number 
//then skipping the second repeating number for the first number