#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0;
        vector<int> res;

        while (matrix.size()-1 >= 2*i && matrix[0].size()-1>=2*i ){
            //top complete side 
            for (int j=i; j<matrix[0].size()-i; j++){
                res.push_back(matrix[i][j]);
            }
            //right mid always
            for (int j=i+1; j<matrix.size()-1-i; j++){
                res.push_back(matrix[j][matrix[0].size()-1-i]);
            }

            //bottom complete if top < bottom
            if (i < matrix.size()-1-i){
                for (int j=matrix[0].size()-1-i; j>=i; j--){
                    res.push_back(matrix[matrix.size()-1-i][j]);
                }

            }
            //left mid only if left < right
            if (i < matrix[0].size()-1-i){
                for (int j=matrix.size()-2-i; j>i; j--){
                    res.push_back(matrix[j][i]);
                }
            } 
            i++;
        }
        return res;
    }
};

