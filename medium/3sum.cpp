#include<bits/stdc++.h>
using namespace std;


// so a sum of 5 can be achieved from 2,3 as well as 0,5
//when -5 appears he can create a triplet from both 
//but my solution overwites a pair to another pair
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> m1; //store every number here 
        unordered_map<int, pair<int,int>> m2; //store sum of all two pairs with their index
        //make a set to contain only unique triplets
        set<vector<int>> ans; 

        for (int i=0; i<nums.size(); i++){
            //find a triplet
            if (m2.find(0-nums[i]) != m2.end()){
                //sort the triplet so as to always maintain generality
                vector<int> triplet={nums[i], nums[m2[0-nums[i]].second], nums[m2[0-nums[i]].first]};
                sort(triplet.begin(), triplet.end());
                ans.insert(triplet);
            }

            //add this number to all singlets so far
            unordered_map<int, int>::iterator it = m1.begin();
            while (it != m1.end()){
                m2[nums[i]+it->first] = {i, it->second};  //find sum of m1[it] and i 
                it++;
            }
            //add this is a singlet for future elements
            m1[nums[i]] = i;
        }  
        
        vector<vector<int>> ans2;
        for (auto it = ans.begin(); it != ans.end(); it++) ans2.push_back(*it);
        return ans2;

    }
};