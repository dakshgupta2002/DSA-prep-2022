#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res=0;

        for (int i=0; i<strs[0].length(); i++) {
            //check if i'th col is sorted
            for (int j=1; j<strs.size(); j++){
                if (strs[j][i] < strs[j-1][i]){
                    res++;
                    break;
                }
            } 
        }
        return res;
    }
};