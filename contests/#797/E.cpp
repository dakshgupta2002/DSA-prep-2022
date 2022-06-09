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
    int n,k; cin>>n>>k;
    vi nums(k, 0);
    ll cost=0;

    fo(i, n){
        ll w; cin>>w;
        cost += w/k; //remainder is removed here
        nums[w%k]++;
    }
    //we try to compensate the remainder
    int i=1;
    while(i<=k-1){
        if (nums[i]==0) i++;
        else{
            int j = k-i;

            while (j <= k-1){
                if (i == j){
                    int pairs = nums[i]/2;
                    cost += pairs;
                    nums[j]-=2*pairs;    
                    j++;                
                }else{
                    int pairs = min(nums[i], nums[j]);

                    nums[i]-=pairs;
                    nums[j]-=pairs;
                    cost += pairs;
                }

                if (nums[i]==0) break;
                if (nums[j]==0) j++;
            }
            i++;
        }
    }

    cout << cost << endl;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   
    int tc; cin >> tc;
    fo(i, tc) {
        solve();
    }

}




