#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0; //1st char
        unordered_map<char, int> m1;
        int i=0, j=0;

        while (j<s.length()){
            if (m1[s[j]] == 0){
                //include this char
                m1[s[j]]++;
                max_length = max(max_length, j-i+1);
                j++;
            }else{
                m1[s[i]]--;
                i++;
            }
        }

        return max_length;
    }
};