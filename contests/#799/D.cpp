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
    string s; cin>>s;
    int x; cin >> x;
    int pal=0;
    int min_a = x%60;
    int hour_a = x/60;

    int min = 10*(s[3]-'0')+(s[4]-'0');
    int hour = 10*(s[0]-'0')+(s[1]-'0');
    // cout << min << hour << endl;
    while (true){
        //verify pal
        if (hour/10==min%10 && hour%10==min/10){
            pal++;
        }
        //add min hour
        if (min+min_a>=60){
            hour++;
            min = min+min_a-60;
        }
        else{
            min = min+min_a;
        }
        hour+=hour_a;
        hour%=24;

        //verify loop
        // cout << hour << " " << min << endl;

        if (hour == 10*(s[0]-'0')+(s[1]-'0') && min== 10*(s[3]-'0')+(s[4]-'0')){
            cout << pal << endl;
            return;
        }
    }

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