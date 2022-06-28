#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0;
        for (int i=0; i<n.length(); i++){
            maxi = max(maxi, n[i]-'0');
            if (maxi==9) return 9;
        }
        return maxi;
    }
};