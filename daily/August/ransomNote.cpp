#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> rn(26), mgz(26);
        for (auto &i: ransomNote) rn[i-'a']++;
        for (auto &i: magazine) mgz[i-'a']++;

        for (int i=0; i<26; i++) if (rn[i] > mgz[i]) return false;
        return true;      
    }
};