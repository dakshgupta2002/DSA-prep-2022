#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //intersection of intervals
        sort(points.begin(), points.end());
        int arrows = 1;
        int start = points[0][0], end = points[0][1];      

        for (int i=0; i<points.size(); i++) {
            if (points[i][0] <= end){ //there is an intersection
                start = points[i][0];
                end = min(end, points[i][1]);
            } else {
                start = points[i][0]; end = points[i][1];
                arrows ++;
            }
        }
        return arrows;
    }
};