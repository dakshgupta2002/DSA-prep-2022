#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    bool isChild(string parent, string child){
        int i=0, j=0;
        int diff = 0;
        while (i<parent.length() && j<child.length()){
            if (parent[i] != child[j]){
                if (!diff){ 
                    j++;
                    diff=1;
                }
                else return false;
            }else {
                i++;
                j++;
            }
        }
        if (diff==1 && i==parent.length() && j==child.length()) return true;
        if (diff==0 && i==parent.length() && j==child.length()-1) return true;
        return false;
    }

    int findChildren(vector<string>& words, vector<int>& dp, int i){
        if (dp[i]!=0) return dp[i]; // max xhain from this index

        dp[i]=1;
        //find the max string that this parent can adopt
        for (int j=i+1; j<words.size(); j++){
            if (isChild(words[i], words[j])){
                dp[i] = max(dp[i], 1+findChildren(words, dp, j));
            }
        }
        return dp[i];
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), []
            (const string& a, const string& b){
                return a.length() < b.length();
            });

        vector<int> dp(words.size(), 0);
        int max_chain=1;

        for(int i=0; i<words.size(); i++){
            max_chain = max(max_chain, findChildren(words, dp, i));
        }

        // for(int i=0; i<words.size(); i++){
        //     cout<<words[i]<<" "<<dp[i]<<endl;
        // }

        return max_chain;
    }
};

class Solution{
    int longestStrChain(vector<string>& words){
        sort(words.begin(), words.end(), []
            (const string& a, const string& b){
                return a.length() < b.length();
        });
        map<string, int> dp;

        //begin from back, try to find the value for 
    }
};