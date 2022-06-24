#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) return 0;
        sort(nums.begin(), nums.end()); //O(NlogN)

        int i=0, j=0, longest=0;
        int curr=1;

        while (j<nums.size()-1){
            if (nums[j]+1 == nums[j+1]){
                curr++;
                longest = max(longest, curr);
            }else if (nums[j]==nums[j+1]) j++;
            else {
                i=j+1; j=i;
                curr=0;
            }
        }

        return longest;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // insertion in unordered map is average O(1)
        unordered_map<int, bool> exist;
        for (int i=0; i<nums.size(); i++) exist[nums[i]]=1;
        int ans = 0;

        for (int i=0; i<nums.size(); i++){
            //if this can be a head, find the max chain it can form
            if (exist[nums[i]-1]) continue; //it is a child and it wont give max answer

            int count = 1;
            while (exist[nums[i]+count]){
                count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }

};