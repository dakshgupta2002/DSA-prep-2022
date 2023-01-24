#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> getCoord(int i, int n){
        int row = n-1 - (i-1)/n, c;
        i-=(n-1 - row)*n;
        int move_to_right = (n-row)%2;
        if (move_to_right) c= i-1;
        else c= n-i;
        
        return {row, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        
        vector<int> moves(n*n+1, INT_MAX);
        moves[1]=0;
        
        queue<int> q;
        q.push(1);
        
        while (q.size()){
            int next, curr=q.front(); q.pop(); //arranging vars
            if (curr==n*n) return moves[curr]; //base case satisfied

            for (int d=1; d<=6 && curr+d<=n*n; d++){ //rolling dice
                int r=getCoord(curr+d, n).first, c=getCoord(curr+d, n).second;

                if (board[r][c]!=-1)next = board[r][c]; //skipped by the ladder or snake
                else next = curr+d; // explore this node
                
                if (moves[next] > 1+moves[curr]){ //if lesser moves, explore again
                    moves[next] = 1 +moves[curr];
                    q.push(next);
                }
            }
        }
        return -1;
    }
};