#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int trap(vector<int>& height) {
        vector<int> prefixMax(height.size(),0), suffixMax(height.size(), 0);
        int ans=0;
        for(int i=1; i<height.size(); i++){
            prefixMax[i] = max(prefixMax[i-1], height[i-1]);
        }
        for (int i=height.size()-2; i>=0; i--){
            suffixMax[i] = max(suffixMax[i+1], height[i+1]);
        }
        for (int i=1; i<height.size()-1; i++){
            int h = min(prefixMax[i], suffixMax[i]);
            ans += max(0, h - height[i]);
        }

        return ans;
    }
};

class Solution{
public:
    int trap(vector<int> height){
        int l=0, r=height.size()-1;
        int l_max=0, r_max=0;
        int ans = 0;

        // move to find better max
        while (l<=r){
            l_max=max(l_max, height[l]); 
            r_max=max(r_max, height[r]);
            if (l_max<=r_max){
                ans += max(0, min(l_max, r_max) - height[l]);
                l++;
            }else{
                ans += max(0, min(l_max, r_max)-height[r]);
                r--;
            }
        }

        return ans;
    }
};