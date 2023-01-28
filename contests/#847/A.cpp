#include <bits/stdc++.h>
using namespace std;

int main() {

    string pi = "3141592653589793238462643383279502884197";

    int tc=1; 
    cin >> tc;
    while (tc--){
        string n; cin>>n;
        int ans=0;
        for (int i=0; i<n.length(); i++){
            if (n[i]!=pi[i]) break;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}