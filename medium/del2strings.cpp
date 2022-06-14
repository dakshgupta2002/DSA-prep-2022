#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcs (string s1, string s2, int m, int n, vector<vector<int>> &dp){
        if (m== || n==0) return 0;
        if (dp[m][n]!=-1) return dp[m][n];
        if (s1[m-1] == s2[n-1]) return dp[m][n] = 1 + lcs(s1, s2, m-1, n-1, dp);
        else return dp[m][n] = max(lcs(s1, s2, m, n-1, dp), lcs(s1, s2, m-1, n, dp));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        return lcs(word1, word2, 0, 0, dp);
    }
};