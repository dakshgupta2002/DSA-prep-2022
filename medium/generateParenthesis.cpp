#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recurr(vector<string> &res, int open, int close, int n, string temp){
        if (open == n && close==n){
            res.push_back(temp);
            return;
        }
        if (open<n) recurr(res, open+1, close, n, temp+"(");
        if (open > close){
            recurr(res, open, close+1, n, temp+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recurr(res, 0, 0, n, "");
        return res;
    }
};