#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    vector<pair<int, int>> intervals;
    MyCalendar() {
        intervals.clear();
    }
    
    bool book(int start, int end) {
        for (auto &interval: intervals){
            //see if this start-end overlaps some other event
            if (start >= interval.first && start <= interval.second ||
                end >= interval.first && end <= interval.second ||
                start <= interval.first && end >= interval.second){
                    return false;
                }
        }

        intervals.push_back({start, end});
        return true;
    }
};