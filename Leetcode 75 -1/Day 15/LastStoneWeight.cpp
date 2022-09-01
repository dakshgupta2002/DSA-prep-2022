#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> st;
        for(auto &i: stones) st.push(i);

        while (st.size()>1){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();

            if(x!=y) st.push(abs(x-y));
        }      

        if(st.size()==1) return st.top();
        return 0;
    }
};