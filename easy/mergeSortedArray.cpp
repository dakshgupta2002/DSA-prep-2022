#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        vector<int> mer;
        
        while (i<m || j<n){
            if (i<m && j<n){
                if (nums1[i]<nums2[j]) {mer.push_back(nums1[i]);i++;}
                else {mer.push_back(nums2[j]); j++;}
            }else if (i<m){
                mer.push_back(nums1[i]); i++;
            }else{
                mer.push_back(nums2[j]); j++;
            }
        }
        
        for (int k=0; k<m+n; k++){nums1[k]=mer[k];}
    }
};