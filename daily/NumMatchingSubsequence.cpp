#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> visited;
    int match(string &s, string &word){
        if (visited[word] == 1) return 1;
        if (visited[word] == -1) return 0;

        int i=0, j=0;
        while (i<s.length()){
            if (s[i]==word[j]){
                i++; j++;
            }else i++;

            if (j==word.length()) {
                visited[word] = 1;
                return true;
            }
        }
        visited[word] = -1;
        return false;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        for (auto &i: words){
            ans += match(s, i);
        }
        return ans;
    }
};