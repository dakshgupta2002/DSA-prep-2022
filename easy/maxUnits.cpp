#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const auto& lhs, const auto& rhs ){
            return lhs[1] > rhs[1];
        }); 
        int units=0;
        int i=0;
        while (truckSize && i<boxTypes.size()){
            if (boxTypes[i][0] <= truckSize){
                units += boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
                i++;
            }else{
                units += truckSize*boxTypes[i][1];
                truckSize=0;
            }
        }      
        return units;
    }
};

class Solution1{
    public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<int> bucket(1001, 0); //no of boxes with units i
        for (auto &i: boxTypes) bucket[i[1] ] += i[0];

        //now use boxes with max units
        int i=1000, units=0;
        while (truckSize && i>0){
            if (bucket[i] <= truckSize){
                units += i*bucket[i];
                truckSize-=bucket[i];
                i--;
            }else{
                units += truckSize*i;
                truckSize=0;
            }
        }

        return units;
    }
};