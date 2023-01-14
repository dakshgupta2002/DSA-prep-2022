#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<set<char>> eq;
        for (int i=0; i<26; i++) {eq.push_back({char('a'+i)});}

        for (int j=0; j<s1.length(); j++){
            cout << "Adding equivalence of chars " << s1[j] << " and " << s2[j] << endl; 
            int idx1=-1, idx2=-1;
            set<char>::iterator it;

            for (int i=0; i<26; i++){
                for (it=eq[i].begin(); it!=eq[i].end(); it++){
                    if (*it == s1[j]) {cout << ""; idx1=i;}
                    if (*it == s2[j]) {cout << ""; idx2=i;}
                }
            }
            cout << "Merging sets " << idx1 << " and " << idx2 << endl;
            if (idx1==idx2) continue; //Already in the same set 
            else{ //Insert chars of 2nd set into the 1st and clear the 2nd
                for (it=eq[idx2].begin(); it!=eq[idx2].end(); it++) {eq[idx1].insert(*it);}
                eq[idx2].clear();
            }
        }

        string res="";
        for (int j=0; j<baseStr.length(); j++){
            set<char>::iterator it;

            for (int i=0; i<26; i++){
                for (it=eq[i].begin(); it!=eq[i].end(); it++){
                    if (*it == baseStr[j]){
                        res += *(eq[i].begin());
                        break;
                    }
                }
            }
        }
        return res;
    }
};