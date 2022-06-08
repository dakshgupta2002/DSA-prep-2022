#include<bits/stdc++.h>
using namespace std;


//O(nlogn) time and O(1) space
class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size()-1; i+=2){
            if (nums[i]!=nums[i+1]) return nums[i];
        }      
    }
};

//O(n) time and O(n) space
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int, int> appear;

        for (int i=0; i<nums.size(); i++){
            appear[nums[i]]++;
        }

        for (auto it=appear.begin(); it!=appear.end(); it++){
            if (it->second==1) return it->first;
        }
    }
};

//need to find a sol in O(n) time and O(1) space
//that means no more ds but only one loop 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //pending
    }
};