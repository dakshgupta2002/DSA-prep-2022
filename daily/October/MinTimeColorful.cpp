#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // max to pick if consec found
        int res=0;
        int j=0;
        while (; j<colors.length()-1; j++){
            // the same stack of color, find maximum time 
            int maxTime = neededTime[j];
            res+=neededTime[j];
            while (j<colors.length()-1 && colors[j] == colors[j+1]){
                maxTime = max(maxTime, colors[j+1]);
                res+=neededTime[j+1];
                j++;
            }
            res-=maxTime;
        }
        return res;
    }
};