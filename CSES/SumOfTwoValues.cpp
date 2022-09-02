#include <bits/stdc++.h>
using namespace std;

int main(){
    map<long long int, long long int> c;
    long long n, x;
    cin>>n>>x;

    vector<long long int> nums(n);
    for (int i=0; i<n; i++) cin >> nums[i];

    for (int i=0; i<n; i++){
        if(c[x-nums[i]]) {
            cout << c[x-nums[i]] << " " << i+1;
            return 0;
        }
        c[nums[i]]=i+1;
    }
    cout << "IMPOSSIBLE";

    return 0;
}