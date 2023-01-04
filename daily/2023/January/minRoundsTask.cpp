#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumRounds(vector<int>& tasks) {
    sort(tasks.begin(), tasks.end());
    int ans = 0;
    int i=0, j=0;

    while (i<tasks.size() && j<tasks.size()) {
      int currTask = 0;
      while (j<tasks.size() && tasks[i] == tasks[j]){
        currTask++;
        j++;
      }
      //check the number of rounds required
      if (currTask == 1) return -1;
      if (currTask % 3 == 0) ans += currTask/3;
      else ans += currTask/3 + 1;

      i=j;
    }

    return ans;
  }
};