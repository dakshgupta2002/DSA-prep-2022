#include<bits/stdc++.h>
using namespace std;

//O(N) division
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0, prod=1;
        vector<int> res(nums.size());

        for (int i=0; i<nums.size(); i++){
            if (nums[i]==0) zero++;
            else prod*=nums[i];
        }

        if (zero > 1) return res;       
        else if (zero == 1){
            for(int i=0; i<nums.size(); i++) {
                if (nums[i]==0) res[i]=prod;
            }
        }else{
            for (int i=0; i<nums.size(); i++) res[i] = prod/nums[i];
        }

        return res;
    }
};

//O(N) prefix suffix 

class Solution1{
public:
    vector<int>  productExceptSelf(vector<int>& nums) {
        //multiple the prefix and the suffix of every element
        vector<int> res(nums.size(), 1);

        int pre=1;
        for (int i=0; i<nums.size(); i++){
            res[i]*=pre;
            pre*=nums[i];
        }
        int suf=1;
        for (int i=nums.size()-1; i>=0; i--){
            res[i]*=suf;
            suf*=nums[i];
        }
        return res;
    }
};