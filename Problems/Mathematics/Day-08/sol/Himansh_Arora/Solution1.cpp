//problem link- https://codeforces.com/problemset/problem/2098/B
//submission link- https://codeforces.com/problemset/submission/2098/356194738
//approach- Find the leftmost and rightmost possible medians after removal of k bars
//          all houses in between are possible medians 
//Time- O(nlog(n))





#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sp << " " <<
#define int long long
#define fora(a) for(auto i:a)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define forn(i,n) for(int i=0; i<n; i++)
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define inputv(a) {for(int i=0;i<n;i++) cin>>a[i];}
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) x.begin(),x.end()

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


const int MOD = 1e9 + 7;
ll addMod(ll a, ll b) { return (a + b) % MOD; }
ll subMod(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mulMod(ll a, ll b) { return (a * b) % MOD; }

ll powerMod(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = mulMod(res, a);
        a = mulMod(a, a);
        b >>= 1;
    }
    return res;
}





void solve() {
    int n,k;
    cin>>n>>k;
    vi a(n);
    inputv(a);
    sort(all(a));

    int leftMed=a[(n-1-k)/2];
    int rightMed=a[(n-1)-((n-1-k)/2)];


     cout<<rightMed-leftMed+1<<endl;
}





signed main() {
    fast_io();
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
