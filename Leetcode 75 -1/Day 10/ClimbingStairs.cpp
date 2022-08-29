#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int x=1, y=1;

        for (int i=n-2; i>=0; i--){
            int z = x;
            x+=y;
            y=z;
        }
        return x;
    }
};