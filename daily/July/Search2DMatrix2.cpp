#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=matrix.size()-1, j=0;

        while (i>=0 && j<matrix[0].size()){
            int num = matrix[i][j];

            if (num == target) return true;
            if(num > target) i--;
            else j++;
        }
        return false;
    }
};