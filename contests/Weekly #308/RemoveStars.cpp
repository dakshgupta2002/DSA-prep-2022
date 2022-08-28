#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeStars(string s) {
        int i=s.length()-1;
        int stars=0;
        vector<bool> mask(s.length(), true);

        while (i>=0){
            if (s[i]=='*'){
                stars++;
                mask[i]=false;
            }else{
                if (stars){
                    mask[i]=false;
                    stars--;
                }
            }
            i--;
        }
        string res="";
        for (int i=0; i<mask.size(); i++){
            if (mask[i]) res+=s[i];
        }
        return res;
    }
};