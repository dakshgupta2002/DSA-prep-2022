#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int smallest_reachable = nums.size()-1;

        for (int j=nums.size()-1; j>=0; j--) {
            if (j + nums[j] >= smallest_reachable) smallest_reachable = j;
        }
        return smallest_reachable == 0;
    }
};