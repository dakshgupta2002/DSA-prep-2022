#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        
        if (k==0){
          for (int i=0; i<nums1.size(); i++) if (nums1[i]!=nums2[i]) return -1;
          return 0;
        }
        long long total = 0, pos=0;
        for (int i=0; i<nums1.size(); i++) {
            total += (nums1[i]-nums2[i]);  //balances the difference between the two
            if (nums1[i]>nums2[i]) pos+=(nums1[i]-nums2[i]); //from where Ill remove K
            if (abs(nums1[i]-nums2[i])%k!=0) return -1; // if cant be made same
        }
      
        if (total!=0) return -1;
        return (long long)pos/k;
    }
};