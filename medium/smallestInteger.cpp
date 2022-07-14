#include<bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
public:
    int smallest;
    set<int> added; //nums that will be added later

    SmallestInfiniteSet() {
        smallest=1;
    }
    
    int popSmallest() {
        if (added.size()){
            int res = *added.begin();
            added.erase(res);
            return res;
        }else{
            smallest+=1;
            return smallest-1;
        }
    }
    
    void addBack(int num) {
        if (num<smallest){
            added.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */