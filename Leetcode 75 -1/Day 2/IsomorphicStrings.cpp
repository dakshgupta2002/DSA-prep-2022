#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> cmp1, cmp2;

        for (int i=0; i<s.length(); i++){
            if (cmp1.find(s[i])==cmp1.end() && cmp2.find(t[i])==cmp2.end()){
                //pair them up for future
                cmp1[s[i]]=t[i];
                cmp2[t[i]]=s[i];
            }else if (cmp1[s[i]]!=t[i] || cmp2[t[i]]!=s[i]){
                //one of the char is paired to somebody else 
                return false;
            }
        }
        return true;
    }
};