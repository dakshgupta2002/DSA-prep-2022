#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(60, 0);
        for (auto &i: s) freq[i-'A']++;

        int len=0; bool center = false;
        for (auto &i: freq){
            if (i%2==0) len+=i;
            else{
                len+=i-1;
                if (!center){
                    center=true;
                    len++;
                }
            }
        }
        return len;
    }
};