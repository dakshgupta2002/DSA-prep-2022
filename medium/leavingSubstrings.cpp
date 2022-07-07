#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPoss(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>>& dp){
        //base case
        if (i == s1.length()) {
            return s2.substr(j) == s3.substr(i+j);
        }
        if (j == s2.length()) {
            return s1.substr(i) == s3.substr(i+j);
        }

        //memo
        if (dp[i][j]!=-1) return dp[i][j];

        //recurse forward to a possible solution
        if (s1[i]==s3[i+j] && s2[j]==s3[i+j]){
            return dp[i][j] = isPoss(s1, s2, s3, i+1, j, dp) || isPoss(s1, s2, s3, i, j+1, dp);
        }else if (s1[i]==s3[i+j]){
            return dp[i][j] = isPoss(s1, s2, s3, i+1, j, dp);
        }else if (s2[j]==s3[i+j]){
            return dp[i][j] = isPoss(s1, s2, s3, i, j+1, dp);
        }else{
            return dp[i][j] = 0;
        }
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;

        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
        return isPoss(s1, s2, s3, 0, 0, dp)? true: false;
    }
};