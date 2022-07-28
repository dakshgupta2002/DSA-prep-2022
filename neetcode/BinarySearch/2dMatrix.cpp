#include<bits/stdc++.h>
using namespace std;

// O(logM * logN)
class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l_row=0, h_row=matrix.size()-1;
        while (l_row<=h_row){
            int m_row=l_row+(h_row-l_row)/2;

            if (matrix[m_row][0] > target) h_row=m_row-1;
            else if (matrix[m_row][matrix[0].size()-1] < target) l_row=m_row+1;
            else{
                //number exists in this range only
                int l_col=0, h_col=matrix[0].size()-1;
                while (l_col<=h_col){
                    int m_col=l_col+(h_col-l_col)/2;
                    if (matrix[m_row][m_col] == target) return true;
                    else if (matrix[m_row][m_col] < target) l_col=m_col+1;
                    else h_col=m_col-1;
                }
                return false;
            }
        }
        return false;
    }
};

//O(log(M+N)) approach by thinking of the matrix as a long list
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0, end = matrix.size()*matrix[0].size()-1;
        while (start <= end){
            int mid = start + (end-start)/2;
            int row = mid/matrix[0].size(), col=mid%matrix[0].size();
            if (matrix[row][col]==target) return true;
            else if (matrix[row][col] < target) start = mid+1;
            else end = mid-1;
        }
        return false;
    }
};