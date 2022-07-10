#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first = cost[cost.size()-2], second=cost[cost.size()-1];

        for (int i=cost.size()-3; i>=0; i--){
            int temp = cost[i] + min(first, second);
            second=first; first=temp;
        }

        return min(first, second);
    }
};