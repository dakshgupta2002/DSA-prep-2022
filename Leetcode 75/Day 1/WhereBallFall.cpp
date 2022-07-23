#include <bits/stdc++.h>
#include<iostream
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res(grid[0].size());

        for (int i=0; i<grid[0].size(); i++){
            int col=i; //where it will fall
            for (int j=0; j<grid.size(); j++){
                if (grid[j][col]==1){
                    //goes to right
                    if (col >= grid[0].size()-1 || grid[j][col+1] == -1){
                        col = -1;
                        break;
                    }else{
                        col++;
                    }
                }else{
                    if (col<=0 || grid[j][col-1]==1){
                        col=-1;
                        break;
                    }else col --;
                }
            }
            res[i] = col;
        }      
    }
};