#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int m, p, M=1000000007;

    int  addEle(int n, int k){
        if (k==p) return 1; //condition in this permutation satisfied
        if (n==m+1) return 0; //out of bound
        if (dp[n][k] != -1) return dp[n][k];

        int res=0;
        // number of ways to place (n)th num in array
        for (int i=n; i>=max(1, n-(p-k)); i--){ 
            // place at (i)th pos in the array
            int v = addEle(n+1, k+(n-i)) % M;
            cout << n << " " << k << " " << i << " " << v << endl;
            res = (res+v) % M;
        }
        
        return dp[n][k] = res;
    }
    int kInversePairs(int n, int k) {
        m=n; p=k;
        dp.resize(n+1, vector<int>(k+1, -1));

        return addEle(1, 0);
    }
};