#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) return {};
        int i=0, j=0;
        vector<int> chars(26, 0), target(26, 0);
        vector<int> res;
        int matched=0;

        for (int i=0; i<p.length(); i++) target[p[i]-'a']++;
        while (j<p.length()) chars[s[j++]-'a']++;

        for (int i=0; i<26; i++) if(target[i] == chars[i]) matched++;
        
        while (j<s.length()){
            if (matched == 26) res.push_back(i);

            //add at index j
            if (target[s[j]-'a'] == chars[s[j]-'a']) matched--;
            else if (target[s[j]-'a'] == chars[s[j]-'a'] + 1)matched++;
            chars[s[j]-'a']++;
            j++;

            //remove from index i
            if (target[s[i]-'a'] == chars[s[i]-'a']) matched--;
            else if (target[s[i]-'a'] == chars[s[i]-'a'] - 1)matched++;
            chars[s[i]-'a']--;
            i++;
        }
        if (matched==26) res.push_back(i);
        return res;
    }
};