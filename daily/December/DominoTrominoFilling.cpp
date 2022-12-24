#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod;
    vector<long> dp_c, dp_p;

    long complete(int n){
        if (n<0) return 0;
        if (n==0) return 1;
        if (dp_c[n] != -1) return dp_c[n];

        return
            dp_c[n] = ((complete(n-1) % mod) + (complete(n-2) % mod) + ((2*partial(n-1)) % mod)) % mod;
    }
    
    long partial(int n){
        if (n<=1) return 0;
        if (n==2) return 1; 
        if (dp_p[n] != -1) return dp_p[n];

        return 
            dp_p[n] = ((partial(n-1) % mod) + (complete(n-2) % mod)) % mod;
    }

    int numTilings(int n) {
        mod = 1000000007;
        dp_c.resize(n+1, -1); dp_p.resize(n+1, -1);
        cout << 1782286921 % mod << endl;  
        return complete(n);
    }
};