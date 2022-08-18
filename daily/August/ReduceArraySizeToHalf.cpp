#include <bits/stdc++.h>
using namespace std;

// Time: O(N*logN)
// Space: O(N)
class Solution1 () {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> freq;
        for(auto &i: arr) freq[arr]++;

        priority_queue<int> maxFreq;
        for (auto it: freq) maxFreq.push(it.second);

        int reqdNums = 0, deletedInts=0;

        while (deletedInts < arr.size()/2 + arr.size()%2){
            reqdNums++;
            deletedInts+=maxFreq.top();
            maxFreq.pop();
        }

        return reqdNums;
    }
};