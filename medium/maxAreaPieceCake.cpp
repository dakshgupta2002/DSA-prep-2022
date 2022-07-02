#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxWidth=max(verticalCuts[0], w-verticalCuts[verticalCuts.size()-1]);
        int maxHeight=max(horizontalCuts[0], h-horizontalCuts[horizontalCuts.size()-1]);

        int i=0, j=1;
        while (i<horizontalCuts.size() && j<horizontalCuts.size()){
            maxHeight = max(horizontalCuts[j]-horizontalCuts[i], maxHeight);
            i++; j++;
        }      

        i=0, j=1; 
        while (i<verticalCuts.size() && j<verticalCuts.size()){
            maxWidth=max(maxWidth, verticalCuts[j]-verticalCuts[i]);
            i++; j++;
        }

        return (1LL*maxHeight*maxWidth)%1000000007;
    }
};