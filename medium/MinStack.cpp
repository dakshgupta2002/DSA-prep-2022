#include <bits/stdc++.h>
using namespace std;


class MinStack {
public:
    stack<int> arr;
    vector<int> minEle(31000, INT32_MAX);

    MinStack() {
    }
    
    void push(int val) {
        arr.push(val);
        minEle[arr.size()] = min(minEle(arr.size()-1), val);
    }
    
    void pop() {
        arr.pop();
    }
    
    int top() {
        return arr.top();
    }
    
    int getMin() {
        return minEle(arr.size());
    }
};