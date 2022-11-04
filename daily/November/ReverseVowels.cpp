#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(string &s, int t){
        if (s[t]=='a' || s[t]=='e' || s[t]=='i' || s[t]=='o' || s[t]=='u' ||
        s[t]=='A' || s[t]=='E' || s[t]=='I' || s[t]=='O' || s[t]=='U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int i=0, j=s.length()-1;

        while (i<j){
            if (isVowel(s, i) && isVowel(s, j)){
                char temp = s[i];
                s[i]=s[j];
                s[j]=temp;
                i++; j--;
            }else if (!isVowel(s, i)) i++;
            else j--;
        }      
        return s;
    }
};