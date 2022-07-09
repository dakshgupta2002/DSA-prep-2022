#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diffFreq(100005, 0);

        for (int i=0; i<nums1.size(); i++){
            diffFreq[abs(nums1[i]-nums2[i])]++; 
            //the index is the occurence of the diff bw each pair
        }

        int red = k1+k2;
        for (int i=diffFreq.size()-1; i>0; i--){
            if (red >diffFreq[i]){
                //reduce all differnce by 1
                diffFreq[i-1] += diffFreq[i];
                red -= diffFreq[i];
                diffFreq[i]=0;
            }else{
                diffFreq[i-1]+=red;
                diffFreq[i]-=red;
                red=0;
                break;
            }
        }

        long long int res = 0;
        for (int i=1; i<diffFreq.size(); i++){
            long long ans=0;
            if (diffFreq[i] !=0){
                ans=1;
                ans*=i;
                ans*=i;
                ans*=diffFreq[i];
            }
            res+=ans;
        }
        return res;
    }
};