#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    int root(int a){
        while (parent[a]!=-1){
            a = root(parent[a]);
        }
        return a;
    }
    void Union(int a, int b){
        int x=root(a), y=root(b);
        if (x!=y){
            parent[max(x,y)]=min(x,y);
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26, -1);
        for (int i=0; i<s1.length(); i++) Union(s1[i]-'a', s2[i]-'a');
        string res="";
        for (int i=0; i<baseStr.length(); i++){
            // cout << "Root of " << baseStr[i] << " is" << char(root(baseStr[i]-'a')+'a') << endl;
            res+=char(root(baseStr[i]-'a')+'a');
        }
        return res;
    }
};