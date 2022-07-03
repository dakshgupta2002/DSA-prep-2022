#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int start = nums[0];
        int res = 1;

        int flag = -1; // -1 is find any, 0 is find smaller, 1 is big
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == start)
                continue;
            if (flag == -1)
            {
                if (nums[i] > start)
                    flag = 0; // next find small
                else
                    flag = 1;

                start = nums[i];
                res += 1;
            }
            else if (flag == 1)
            {
                if (nums[i] > start)
                {
                    flag = 0; // next find small
                    start = nums[i];
                    res += 1;
                }
                else
                    start = nums[i];
            }
            else if (flag == 0)
            {
                if (nums[i] < start)
                {
                    flag = 1;
                    start = nums[i];
                    res += 1;
                }
                else
                {
                    start = nums[i];
                }
            }
        }
        return res;
    }
};