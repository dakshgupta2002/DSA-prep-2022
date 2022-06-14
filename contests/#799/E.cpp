#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define deb(x) cout << #x << " " << x <<endl;
#define sum(a) accumulate(a.begin(), a.end(), 0);

#define fo(i, n)  for (auto i = 0; i < n; i++)
#define foitr(it, l) for (auto it = l.begin(); it != l.end(); it++)

typedef long double ld;
typedef unsigned long int ull;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end() //sortall(v1)
#define clr(a) memset(a, a.size(), 0)
#define int long long
#define PI 3.1415926535897932384626433832795
const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ld EPS = 1e-9;

#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef multiset<int> msi;







void solve() {
    int n, s;
    cin>>n>>s;
    int summ=0;

    vi v(n);
    fo(i, n){ cin>>v[i]; summ+=v[i];}

    if (s > summ){
        cout << -1 << endl; return;
    }
    if (s==summ){
        cout << 0 << endl; return;
    }
    int ones = 0;

    mii lr, rl;
    fo (i, n){
        if (v[i]==1){
            ones++;
            lr[ones]=i+1; // to reduce k 1s use v ops
        }
    }
    ones=0;
    for(int i=n-1; i>=0; i--){
        if(v[i]==1){
            ones++;
            rl[ones]=n-i;
        }
    }
    int ans = n;
        // cout << "i" << endl;
    //now iterate from lr and from rl 
    for (auto it:lr){
        int removed = it.first;
        int ops = it.second;
        // deb(removed);
        if (summ-s > removed){
            //find from rl 
            ops+= rl[summ-s-removed];
        }
        // deb(ops);
        ans = min(ans, ops);
    }
    //0 1 0 0 0 0 0 1 1 1 0 0 0 

        // cout << "j" << endl;
    for (auto it:rl){
        int removed = it.first;
        int ops = it.second;
        // deb(removed);
        if (summ-s > removed){
            //find from rl 
            ops+= lr[summ-s-removed];
        }
        // deb(ops);
        ans = min(ans, ops);
    }

    cout << ans << endl;
    // cout << "_________________"<<endl; 
}




int32_t main() {
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/daksh/Desktop/VSCode/DSAprep22/input.txt", "r", stdin);
        freopen("C:/Users/daksh/Desktop/VSCode/DSAprep22/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   
    int tc=1; 
    cin >> tc;
    fo(i, tc) {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    #ifndef ONLINE_JUDGE
        auto start1 = high_resolution_clock::now();
        auto stop1 = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop1 - start1);
        cout << endl << endl << "[Finished in: " << duration.count()  << "ms ]" << endl;
    #endif

}