#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Solution {
public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    //sort the tasks by the arrival time
    for (int i=0; i<tasks.size(); i++) tasks[i].push_back(i);
    sort(tasks.begin(), tasks.end());
    
    priority_queue<pii, vector<pii>, greater<pii>> enqueued;
    int task_index = 0, timer=1;
    vector<int> res;

    while (true){
      if (task_index == tasks.size()) break;
      //tasks that have enqueued uptil the current time should
      while (task_index<tasks.size() && tasks[task_index][0] <= timer){
        enqueued.push({tasks[task_index][1], tasks[task_index][2]});
        task_index++;
      }
      //complete the non pre-emptive task with lower priority
      if (enqueued.size()){
        timer+=enqueued.top().first;
        res.push_back(enqueued.top().second);
        enqueued.pop();
      // skip the timer to the next task available in pool
      }else timer = tasks[task_index][0];
    }
    while (enqueued.size()){
      res.push_back(enqueued.top().second);
      enqueued.pop();
    }
    return res;
  }
};