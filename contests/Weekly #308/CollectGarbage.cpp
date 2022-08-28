#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        //M, P, G
        vector<int> last(3, garbage.size()-1);
        vector<bool> occured(3, false);
        int t=0;

        for (int i=garbage.size()-1; i>=0; i--){
            t+=garbage[i].length();

            for (int j=0; j<garbage[i].length(); j++){
                if (garbage[i][j]=='M') occured[0]=true;
                else if (garbage[i][j]=='P') occured[1]=true;
                else occured[2]=true;
            }
            for (int j=0; j<3; j++){
                if (occured[j]==false){
                    last[j]=i-1;
                }
            }
        }

        for (int i=0; i<3; i++){
            for (int j=0; j<last[i]; j++) t+=travel[j];
        }
        return t;
    }
};