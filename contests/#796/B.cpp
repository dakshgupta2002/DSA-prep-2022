//JAI MATA DI
//JAI SHREE RAM

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x <<endl;
#define sum(a) accumulate(a.begin(), a.end(), 0);

#define fo(i, n)  for (auto i = 0; i < n; i++)
#define foitr(it, l) for (auto it = l.begin(); it != l.end(); it++)

typedef long double ld;
typedef unsigned long int ull;
typedef long long int ll;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end() //sortall(v1)
#define clr(a) memset(a, a.size(), 0)

#define PI 3.1415926535897932384626433832795
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef multiset<int> msi;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}


void solve() {
    ll n; cin>>n;
    vll even;
    int ans=0; 
    ll odd=0;

    fo(i, n){
        ll x; cin>>x;
        if(x%2 == 0) even.pb(x);
        else odd++;
    }

    if (even.size()==0){
        cout << 0 << endl;
        return;

    }

    int min_factor=40;

    for (int i=32; i>0; --i){
        for (int j=even.size()-1; j>=0; j--){
            ll x = pow(2,i);

            if (even[j]%x==0){
                // cout << "X"<<even[j] << "factor" << i << endl;
                even[j]=-1;
                min_factor=min(min_factor, i);
            }
        }
    }
    // cout << min_factor << endl;
    ans+=even.size()-1;
    ans+=odd>0? 1 :min_factor;

    cout << ans << endl;


}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   
    int tc; cin >> tc;
    fo(i, tc) {
        solve();
    }

}




