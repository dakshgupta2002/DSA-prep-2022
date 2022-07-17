#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

        for (int i = 1; i <= n; i++) { //placing i th number
            for (int j = 0; j <= k; j++) { // saving states for pairs to be made
                if (j == 0) dp[i][j] = 1;
                else {
                    for (int p = 0; p <= min(j, i - 1); p++) 
                        // i can generate p pairs from this number i
                        // find the permutations for j-p pairs
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % 1000000007;
                }
            }
        }
        return dp[n][k];
    }
};