#include <bits/stdc++.h>
using namespace std;

int total;
vector<int> nums;
vector<vector<int>> dp;

int build(int i, int x){
    cout << abs(total-2*x) << endl;
    if (i==nums.size()) return abs(total-2*x);
    if (dp[x][i] != -1) return dp[x][i];

    return dp[x][i] = min(build(i+1, x+nums[i]), build(i+1, x));    
}

int minSubsetSumDifference(vector<int>& arr, int n){
    nums=arr;
    total = accumulate(nums.begin(), nums.end(), 0);
    dp.resize(total+1, vector<int>(arr.size(), -1));

    return build(0, 0);
}
