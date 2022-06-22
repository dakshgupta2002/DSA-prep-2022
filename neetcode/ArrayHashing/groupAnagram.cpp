#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> group;

        for (int i=0; i<strs.size(); i++){

            string original = strs[i];
            sort(strs[i].begin(), strs[i].end());
            group[strs[i]].push_back(original);
        }

        vector<vector<string>> res;
        for (auto it:group){
            res.push_back(it.second);
        }
        return res;
    }
};