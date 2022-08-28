#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> answer(queries.size());

        for (int i=0; i<queries.size(); i++){
            //find sum
            int s=0, t=0;
            for (int j=0; j<nums.size(); j++){
                if (s+nums[j]>queries[i]) break;
                s+=nums[j];
                t++;
            }
            answer[i]=t;
        }
        return answer;
    }
};