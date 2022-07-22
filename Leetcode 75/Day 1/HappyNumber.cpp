#include <bits/stdc++.h>
using namespace std;

//Hash cycle detection
class Solution1 {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> v;
        while (v[n]==false){
            if (n==1) return true;

            int temp = 0;
            while (n) {
                temp += (n%10)*(n%10);
                n/=10;
            }
            n=temp;
        }
        return false;
    }
};

//Floyd's cycle detection 
class Solution {
public:
    int getNext(int n){
        int temp = 0;
        while (n) {
            temp += (n%10)*(n%10);
            n/=10;
        }
        return temp;
    }

    bool isHappy(int n) {
        int s = n, f = n;

        while (true){
            if (s == 1 || f == 1) return true;            
            s = getNext(s);
            f = getNext(getNext(f));
            if (s == 1 || f == 1) return true;
            
            if (s==f) return false;
        }
    }
};

