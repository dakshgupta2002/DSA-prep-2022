#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //string to freq mapping
        map<string, int> f;
        for (auto &i: words) f[i]++;
        //freq index stores all words
        vector<vector<string>> w(501);
        for (auto it: f) w[it.second].push_back(it.first);
        //choose first k words
        vector<string> res;
        for (int i=w.size()-1; i>=0; i--){
            if (k==0) return res;

            if (w[i].size()<=k){
                //include complete 
                k-=w[i].size();
                for (auto wo: w[i]) res.push_back(wo);
            }else{
                for (int j=0; j<k; j++) res.push_back(w[i][j]);
                k=0;
            }
        }

        return res;
    }
};