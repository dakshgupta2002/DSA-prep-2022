#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n, k; cin>>n>>k;
    string s; cin>>s;
    int cnt=0, first=-1, last=-1;

    for(int i=0; i<n; i++){ 
        if (s[i]=='1'){
            cnt++;
            last=i;
            if (first==-1) first=i; 
        }   
    }

    int ans = 11*cnt;
    //no 1s
    if (cnt==0){
        cout << 0 << endl;
        return;

    }else if (cnt==1){
        //first try to position last 
        if (s[n-1]=='1'){
            ans-=10;
            cout << ans << endl;
            return;
        }else{
            if (n-1-last <= k){
                ans-=10;
                cout << ans << endl;
                return;
            }
        }

        if (s[0]=='1'){
            ans-=1;
            cout << ans << endl; return;
        }else{
            if (first <= k){
                ans-=1;
                cout << ans << endl; return;
            }
        }

    }else{
        //we can try both

        if (s[n-1]=='1'){
            ans-=10;
        }else{
            if (n-1-last <= k){
                ans-=10;
                k-=n-1-last;
            }
        }

        if (s[0]=='1'){
            ans-=1;
        }else{
            if (first <= k){
                ans-=1;
            }
        }

    }

    cout << ans << endl;
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();

    } 
}