#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0, j=0;
        int w=0;
        int res=k;

        while (j<k){
            if (blocks[j]=='W') w++;
            j++;
        }

        while (j<blocks.length()){
            res = min(res, w);

            if (blocks[i]=='W') w--;
            if (blocks[j]=='W') w++;
            i++; j++;
        }
        return min(res, w);
    }
};