#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1); 
        //we only need to maintain the data of current row

        for (int i=m-2; i>=0; i--){
            for (int j=n-2; j>=0; j--){
                // dp[j] is the value from the bottom 
                // and dp[j+1] is from left
                dp[j] += dp[j+1];
            }
        }
        return dp[0];
    }
};