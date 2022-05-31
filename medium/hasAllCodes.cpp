#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check (string s, string p, int k){
        if (p.length() == k){
            //check if s contains p
            return s.find(p) != string::npos;
        }

        return check(s, p+'0', k) && check(s, p+'1', k);
    }

    bool hasAllCodes(string s, int k) {
        return check (s, "", k);
    }
};