#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> f(26);
        f[s[0]-'A']++;
        int i=0, j=0;

        int ans=k;

        while (i<=j && j<s.length()){
            int maxFreq=0;
            for (int i=0; i<26; i++) maxFreq = max(maxFreq, f[i]);

            if ((j-i+1) - maxFreq <= k){
                ans= max(ans, j-i+1);
                if (j==s.length()-1) break;
                j++;
                f[s[j]-'A']++;
            }else{
                f[s[i]-'A']--;
                i++;
            }
        }  

        return ans;     
    }
};