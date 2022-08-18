#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==1) return strs[0];
        
        int i=0;
        while (true){
            for (int j=0; j<strs.size()-1; j++){
                if (i>=strs[j].length() || i>=strs[j+1].length() || strs[j][i] != strs[j+1][i]){
                    return strs[0].substr(0, i);
                }
            }
            i++;
        }
    }
};