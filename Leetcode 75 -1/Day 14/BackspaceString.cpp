#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a, b;
        for (int i=0; i<s.length(); i++){
            if (s[i]=='#') {if(a.size()>0) a.pop();}
            else {a.push(s[i]);}
        }
        for (int j=0; j<t.length(); j++){
            if (t[j]=='#') {if(b.size()>0) b.pop();}
            else {b.push(t[j]);}
        }

        if (a.size()!=b.size()) return false;
        while (a.size()){
            if (a.top()!=b.top()) return false;
            a.pop();
            b.pop();
        }
        return true;
    }
};