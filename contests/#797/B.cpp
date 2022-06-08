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
    int n; cin >> n;

    vi a(n), b(n);

    
    fo(i, n){
        cin >> a[i];
    }
    fo(i, n){
        cin >> b[i];
    }

    int zero=0;
    int diff=0;
    fo(i, n){
        if (b[i]==0){
            zero++;
        }else{
            diff = a[i] - b[i];
            break;
        }
    }

    if (zero == n){
        cout << "YES" << endl;
        return;
    }

    if (diff < 0){
        cout << "NO" << endl;
        return;
    }
    //otherwise maintain diff 
    fo(i, n){
        if (b[i] == 0 && (a[i]-b[i]>diff)){
            cout << "NO" << endl;
            return;
        }
        if (b[i] != 0 && a[i]-b[i] != diff){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   
    int tc; cin >> tc;
    fo(i, tc) {
        solve();
    }

}




