#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> n(1001, 0), m(1001, 0), res;
        for (auto &i: nums1) n[i]+=1;
        for (auto &j: nums2) m[j]+=1;

        for (int i=0; i<=1000; i++){
            for (int j=0; j<min(n[i], m[i]); j++) res.push_back(i);
        }      
        return res;      
    }
};