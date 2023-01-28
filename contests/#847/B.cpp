#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n, s, r; cin>>n>>s>>r;
        //divide (r) to (n-1) dices with max value (s-r)
        int diff = s-r;
        //1,2,...diff
        int i=1;
        cout << diff << " ";
        while (r>0){
            cout << r/(n-i) << " ";
            r-=(r/(n-i));
            i++; 
        }
        cout << "\n";
    }
}