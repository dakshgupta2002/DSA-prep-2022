#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string longestPalindrome(string s) {
        int longest=0;
        string longest_str=""; 

        for (int i=0; i<s.length(); i++){
            //keep every element at center
            //expand till you not a palindrome 
            int curr=1;
            int left = i, right = i;
            //center cluster 
            while (left >0 && s[left-1] == s[i]){
                curr++; left--;
            }
            while (right < s.length()-1 && s[right+1] == s[i]){
                curr++; right++;
            }
            //mirror elements 
            while (left >0 && right < s.length()-1 && s[left-1] == s[right+1]){
                curr+=2; left--; right++;
            }

            string curr_str = "";
            for (int j=left; j<=right; j++){
                curr_str+=s[j];
            }
            
            if (curr > longest){
                longest = curr;
                longest_str = curr_str;
            }
        }
        return longest_str;
    }
};