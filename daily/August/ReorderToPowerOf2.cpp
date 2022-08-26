#include <bits/stdc++.h>
using namespace std;

//iterate over all powers of 2
//match the freq of each digit for both
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> freq(10, 0);
        while (n){
            freq[n%10]++;
            n/=10;
        }

        for (int i=0; i<30; i++){
            vector<int> freqq(10, 0);
            int b = pow(2, i);
            while (b){
                freqq[b%10]++;
                b/=10;
            }
            int match=0;
            for (int i=0; i<10; i++){
                if (freq[i]==freqq[i]) match++;
            }
            if (match==10) return true;
        }
        return false;

    }
};