#include <bits/stdc++.h>
using namespace std;

//O(n^m) Time
class Solution{
public:
    int paint(vector<int> houses, vector<vector<int>> &cost, int target, int i, int charge){
        if (i == houses.size() && target == 1) return charge;
        if (target < 1 || i == houses.size()) return INT32_MAX;

        if (houses[i] != 0){
            // this is already painted last summer, no charge
            if (i>0 && houses[i] != houses[i - 1]) return paint(houses, cost, target-1, i + 1, charge);
            else return paint(houses, cost, target, i + 1, charge);
        }

        else{
            int res = INT32_MAX;

            // choose from all colors which to choose for this house
            for (int j = 0; j < cost[0].size(); j++){
                houses[i] = j + 1; // color chosen is j+1
                if (i>0 && houses[i] != houses[i - 1])
                    res = min(res, paint(houses, cost, target-1, i + 1, cost[i][j]+charge));
                else
                    res = min(res, paint(houses, cost, target, i + 1, cost[i][j]+charge));
            }
            return res;
        }
    }

    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target){

        int res = paint(houses, cost, target, 0, 0);
        if (res == INT32_MAX) return -1;
        return res;
    }
};

