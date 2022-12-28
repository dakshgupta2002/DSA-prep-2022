#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (auto i: piles) pq.push(i);

        while (k--){
            int maxPile = pq.top();
            pq.pop();
            pq.push(maxPile - maxPile/2);
        }
        int total = 0;
        while (pq.size()) {
            total += pq.top();
            pq.pop();
        }
        return total;
    }
};