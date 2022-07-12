#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sum = 0;
    vector<int> match;

    bool chooseSide(int i, vector<long long> sides, long long target)
    {
        if (i == match.size() && sides[0] == target && sides[1] == target && sides[2] == target)
            return true;
        //first backtrack if some length is larger
        if (i == match.size() || sides[0] > target || sides[1] > target || sides[2] > target || sides[3] > target)
            return false;

        for (int s=0; s<4; s++){
            if (sides[s]+match[i]>target) continue;
            int t=s-1;
            while (t>=0) {
                if (sides[t]==sides[s]) break;
                else t--;
            }
            //backtrack if a similar state of sides was tried before 
            if (t!=-1) continue;

            sides[s]+=match[i];
            //if this leads to a solution, return true
            if (chooseSide(i+1, sides, target)) return true;
            sides[s]-=match[i];
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks)
    {
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        match = matchsticks;
        //we need atleast 4 matches
        if (match.size() < 4)
            return false;
        //sorting prevents the number of calls before length of side goes large
        sum = accumulate(match.begin(), match.end(), 0);
        if (sum % 4 != 0)
            return false;
        //if a match cannot be acoomodated anywhere
        for (auto &i : match)
        {
            if (i > sum / 4)
                return false;
        }
        vector<long long> sides = {0, 0, 0, 0};
        return chooseSide(0, sides, sum / 4);
    }
};