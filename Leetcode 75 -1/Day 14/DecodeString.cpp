#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decode(string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i])) res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i])) n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decode(s, i);
                i++; // ']'
                
                while (n-- > 0) res += t;
            }
        }
        return res;
    }

    string decodeString(string s) {
        return decode(s, 0);
    }
};