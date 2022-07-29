#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;

        for (int i=0; i<words.size(); i++){
            if (words[i].length() == pattern.length()){
                //check if pattern same
                vector<char> m(26, '#'), n(26, '#');

                int j;
                for (j=0; j<words[i].length(); j++){
                    // both chars available
                    if (m[words[i][j] - 'a'] == '#' && n[pattern[j] - 'a'] == '#'){
                        m[words[i][j] - 'a'] = pattern[j];
                        n[pattern[j] - 'a'] = words[i][j];
                    // if visited this char before then consistency is required
                    }else if (m[words[i][j] - 'a'] != pattern[j]){
                        break;
                    }
                }

                if (j==words[i].length()) res.push_back(words[i]);
            }
        }        
        return res;
    }
};