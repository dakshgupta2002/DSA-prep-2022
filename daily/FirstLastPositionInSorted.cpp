#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //all numbers greater or lesser than target
        if (nums.size()==0 || nums[nums.size()-1] < target || nums[0] > target) return { -1, -1 };
        //all numbers are target
        if (nums[0]==target && nums[nums.size()-1]==target) return {0, (int)(nums.size()-1)};

        int x=-1, y=-1;
        //find x, ele just smallers than target and maxi pos
        int lo=0, hi=nums.size()-1;
        while (lo<=hi){
            int mid = lo + (hi-lo)/2;
            if (nums[mid] < target){
                x=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        //find y, element just greater than target but mini pos
        lo=0, hi=nums.size()-1;
        while (lo<=hi){
            int mid = lo + (hi-lo)/2;
            if (nums[mid] > target){
                y=mid;
                hi=mid-1;
            }else lo=mid+1;
        }

        //first is not but last number is target and vice-versa
        if (nums[nums.size()-1] == target) return {x+1, (int)(nums.size()-1)};
        if (nums[0]==target) return {0, y-1};

        //it doesnt exist
        if (y-x == 1) return { -1, -1 };
        //its in the center of the array
        return {x+1, y-1};
    }
};