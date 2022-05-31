// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         unordered_map<int, int> m1;
//         set<vector<int>> res;
//         for (int i=0; i<nums.size(); i++) m1[nums[i]]=i;

//         for (int i=0; i<nums.size(); i++){
//             for (int j=i+1; j<nums.size(); j++){
//                 int target = -(nums[i]+nums[j]);
//                 if (m1.find(target) != m1.end() && m1[target] != i && m1[target] != j){
//                     vector<int> v;
//                     v.push_back(nums[i]);
//                     v.push_back(nums[j]);
//                     v.push_back(target);
//                     sort(v.begin(), v.end());
//                     res.insert(v);
//                 }
//             }
//         }
//         vector<vector<int>> ans;
//         for (auto v: res) ans.push_back(v);
//         return ans;
//     }
// };