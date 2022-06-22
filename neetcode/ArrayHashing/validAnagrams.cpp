#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> charCount(26, 0);
        if (s.length() != t.length()) return false;

        for (int i=0; i<s.length(); i++){
            charCount[s[i]-'a']++;
        }

        for (int i=0; i<t.length(); i++){
            charCount[t[i]-'a']--;
            if (charCount[t[i]-'a']<0) return false;
        }

        for (int i=0; i<charCount.size(); i++){
            if (charCount[i]!=0) return false;
        }

        return true;
    }
};