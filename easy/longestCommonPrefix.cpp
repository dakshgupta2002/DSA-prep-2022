#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        int i=0; 
        while (i < strs[0].length()){
            
            for (int j=0; j<strs.size()-1; j++){
                if (i < strs[j].length() && i<strs[j+1].length()
                                    && strs[j][i] == strs[j+1][i]){
                    continue;
                }else{
                    return ans;
                }
            }

            ans += strs[0][i];
            i++;
        }
    }
};