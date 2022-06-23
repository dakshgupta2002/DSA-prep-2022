#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string res = "";

        for (int i=0; i<strs.size(); i++){
            res+=(strs[i].length() + '0');
            res += strs[i];
        }

        return res;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> res;
        int i=0;
        while (i<str.length()){
            int len = str[i]-'0';
            string s="";
            int j=i+1;
            
            while (len--){
                s+=str[j]; 
                j++;
            }
            res.push_back(s);
            i=j+1;
        }

        return res;
    }
};