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
ll getPosOfRightmostSetBit(ll n)
{
    if (n==0) return -1;

    return log2(n&-n)+1;
}
ll getPosOfRightMostUnsetBit(ll n)
{
    // if n = 0, return 1
    if (n == 0)
        return 1;
     
    // if all bits of 'n' are set
    if ((n & (n + 1)) == 0)   
        return -1;
     
    // position of rightmost unset bit in 'n'
    // passing ~n as argument
    return getPosOfRightmostSetBit(~n);       
}

void solve() {
    ll x; cin>>x;
    ll y=0;

    if (x==1){
        cout << 3 << endl;
        return;
    }
    int add=0;
    if (getPosOfRightMostUnsetBit(x)==-1){
        if (x==1){
            add=10;
        }
    }else {
        add=pow(2, getPosOfRightMostUnsetBit(x)-1);
    }
    
    y+= pow(2, getPosOfRightmostSetBit(x)-1);
    x-=y;
    
    if (getPosOfRightmostSetBit(x)!=-1){
        cout << y << endl; return;
    }else{
        y+=add;
    }

    cout << y << endl;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   
    int tc; cin >> tc;
    fo(i, tc) {
        solve();
    }

}




