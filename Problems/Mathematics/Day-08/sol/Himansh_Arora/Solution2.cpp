//problem link-https://codeforces.com/problemset/problem/1999/F
//submission link-https://codeforces.com/problemset/submission/1999/356200292
//approach- Only those cases will contribute in which the number of ones in subsequence
//          is more than the number of zeroes. Using nCr choose cases where ones chosen are in majiority
//Time- O(MAXN)






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

const int MAXN = 200005;
int fact[MAXN], invFact[MAXN];
void precompute(){
    fact[0]=1;
    for(int i=1;i <MAXN;i++){
        fact[i]=mulMod(fact[i-1],i);
    }

    invFact[MAXN-1] = powerMod(fact[MAXN-1], MOD-2);
    for(int i=MAXN-2;i>=0;i--){
        invFact[i]=mulMod(invFact[i+1],(i+1));
    }
}


void solve() {
    int n,k;
    cin>>n>>k;
    vi a(n);
    inputv(a);
    int ans=0LL;
    int Ones=count(all(a),1LL);
    int Zeroes=count(all(a),0LL);

    for(int i=(k/2)+1;i<=k;i++){
            int c;
            int d;
            if(Ones>=i)c=mulMod(mulMod(fact[Ones],invFact[i]),invFact[Ones-i]);
            else c=0;
            if(Zeroes>=k-i)d=mulMod(mulMod(fact[Zeroes],invFact[k-i]),invFact[Zeroes-(k-i)]);
            else d=0;
        ans=addMod(ans,mulMod(c,d));
    }

    cout<<ans<<endl;
}





signed main() {
    fast_io();
    
    int t;
    cin >> t;

    precompute();
    while (t--) {
        solve();
    }
    
    return 0;
}
