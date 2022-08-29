#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> img;
    int col, tar;
    void traverse(int sr, int sc){
        if (sr<0 || sc<0 || sr>=img.size() || sc>=img[0].size()) return;
        if (img[sr][sc] != tar || img[sr][sc]==col) return;

        img[sr][sc]=col;

        traverse(sr, sc-1);
        traverse(sr, sc+1);
        traverse(sr+1, sc);
        traverse(sr-1, sc);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        img = image;
        tar=image[sr][sc];
        col=color;
        traverse(sr, sc);
        return img;
    }
};