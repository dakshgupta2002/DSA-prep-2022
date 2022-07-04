#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        // num with both sides larger should be 1
        vector<int> candies(ratings.size(), 1); 
        vector<int> minPeaks;

        if (ratings.size()>=2){ //first and last ele compare with only l and r
            if (ratings[0] <= ratings[1]) {
                candies[0]=1;
                minPeaks.push_back(0);
            }
            if (ratings[ratings.size()-1] <= ratings[ratings.size()-1]) {
                minPeaks.push_back(candies.size()-1);
                candies[candies.size()-1]=1;
            }
        }

        for (int i=1; i<ratings.size()-1; i++){ // for all other min peaks
            if (ratings[i] <= ratings[i-1] && ratings[i]<=ratings[i+1]){
                candies[i]=1;
                minPeaks.push_back(i);
            }
        }  

        //for every min peak search left right and give more candies 
        for (int i=0; i<minPeaks.size(); i++){
            //search left 
            int l=minPeaks[i]-1;
            while (l>=0 && ratings[l] > ratings[l+1]){
                candies[l]=max(candies[l+1]+1, candies[l]);
                l--;
            }
            int r=minPeaks[i]+1;
            while (r<candies.size() && ratings[r] > ratings[r-1]){
                candies[r] = max(candies[r-1]+1, candies[r]);
                r++;
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);

    }
};