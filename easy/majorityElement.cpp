#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //using pigeonhole concept, if a majority element is cancelled with every other number 
        //the count still should be > 0, so on every step if num is diff then reduce 
        //if count =0 then it is not majority obv, so update the candidate 
        int me=nums[0], count=1;
        for (int i=1; i<nums.size(); i++){
            if (nums[i]==me) count++;
            else{
                count--;
                if (count == 0){
                    me=nums[i]; count=1;
                }
            }
        }      

        //verify that the me is valid
        int occur=0;
        for(int i=0; i<nums.size(); i++){
            if (nums[i]==me) occur++;
        }

        if (occur > nums.size()/2) return me;
        return -1;
    }
};