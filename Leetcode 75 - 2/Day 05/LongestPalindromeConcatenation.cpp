#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> freq;
        bool center=false;
        
        for (auto &w: words) freq[w]++;

        //different chars, then need opp
        for (auto &it: freq){
            if (it.first[0] == it.first[1]){
                // even number of 'aa' can be placed as 'aa_ _aa'
                // only one palindromic center is allowed
                ans += (it.second/2)*4;
                if (it.second%2 == 1 && center==false){
                    ans += 2;
                    center=true;
                } 
            }else{
                // find the mirror word for each non-homogenous word and pair
                string mirror = "";
                mirror += it.first[1]+'';
                mirror += it.first[0]+'';
                cout << mirror << endl;
                ans += min(it.second, freq[mirror])*2;
            }
        }
        return ans;
    }
};