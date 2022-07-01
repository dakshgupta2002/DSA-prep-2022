#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (int i=0; i<s.length(); i++){
            freq[s[i]-'a'] = freq[s[i]-'a']+1;
        }
        int ans = 0;

        sort(freq.begin(), freq.end());
        for (int i=freq.size()-1; i>0; i--){
            if (freq[i-1] >= freq[i]){
                ans += freq[i-1] - max(0, freq[i] - 1);
                freq[i-1] = max(0, freq[i] - 1); 
                //we need to reduce the freq of that number but not negative
            }
        }
        return ans;
    }
};