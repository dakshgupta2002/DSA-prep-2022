#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> m;
        int minCard=cards.size()+1;

        for (int i=0; i<cards.size(); i++){
            if (m[cards[i]]==0){
                m[cards[i]] = i+1;
                //saving the occur of this num 
            }else{
                // this same num occured before 
                minCard = min(minCard, i+2-m[cards[i]]);
                m[cards[i]] = i+1;
            }
        }
        if (minCard == cards.size() + 1) return -1;
        return minCard;
    }
};