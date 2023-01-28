#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> children;
    int ans = 1;

    int pathLR(int i, string &s){
        int l=0, r=0;
        for (int c: adjacency[i]){
            if (s[i]==s[c]) pathLR(c, s);
            else{
                int dist = pathLR(c, s);

                if (dist > l) {r=l; l=dist;}
                else if (dist > r) {r=dist;}
            }
        }
        ans = max(ans, l+r+1);
        return l+1;
    }

    int longestPath(vector<int>& parent, string s) {
        adjacency.resize(parent.size());
        for (int i=1; i<parent.size(); i++){
            adjacency[parent[i]].push_back(i);
        }  
        pathLR(0, s);    
        return ans;
};
    }