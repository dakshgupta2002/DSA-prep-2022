#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0;
        vector<int> f1(10, 0), f2(10, 0);

        for (int i=0; i<secret.length(); i++){
            if (secret[i]==guess[i]) {
                bull++;
            }else{
                f1[secret[i]-'0']++;
                f2[guess[i]-'0']++;
            }
        }

        int cow=0;
        for (int i=0; i<10; i++) cow+=min(f1[i], f2[i]);

        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};