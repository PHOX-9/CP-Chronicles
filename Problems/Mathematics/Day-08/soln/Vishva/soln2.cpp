#include<bits/stdc++.h>
#include<queue>
using namespace std;
typedef unordered_map<int, int> umii;
typedef unordered_map<long long, long long> umll;
typedef unordered_map<char, long long> umci;
typedef vector<pair<int, int>> vpi;
typedef vector<int> vi;
typedef long long ll;
typedef vector<long long> vll;
typedef unordered_map<int , bool> umib;
#define sum(v) accumulate(v.begin(), v.end(), 0)
#define endl '\n'
#define f0(i, n) for(long long i = 0; i < n; i++)
#define f1(i, n) for(long long i = 1; i < n; i++)
#define as(v) sort(v.begin(), v.end())
#define all(x) (x).begin(), (x).end()
#define pb push_back
template<class T> umll frequency(vector<T> &v) {umll freq;for(auto &x:v) freq[x]++; return freq;}
template<class T> umci S_frequency(vector<T> &v) {umci freq;for(auto &x:v) freq[x]++; return freq;}
template <class T> void input(vector<T> &v){for(auto &x:v)cin>>x;}
ll power(ll x, ll y){ ll res = 1; while (y > 0){ if (y & 1) res = (ll)(res*x); y = y>>1; x = (ll)(x*x); } return res; }
void pvll(const vector<long long> &arr){for(auto it : arr){cout << it << " ";}cout << endl;}
void pvi(const vector<int> &arr){for(auto it : arr){cout << it << " ";}cout << endl;}


// submission link:-https://codeforces.com/contest/1999/submission/356204297

// time complexity o(nlogn) as sorting 
const int MOD = 1e9 + 7;
const int MAXN = 200000;
 

ll fact[MAXN+1], invfact[MAXN+1];

ll binexpo(ll a, ll b) {
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans = ans*a % MOD;
        }
        a = a*a % MOD;
        b>>=1;
    }
    return ans;
}

ll ncr(ll n, ll r)
{
    if(r<0 || r>n) return 0;
    return (fact[n]*invfact[r]%MOD)*invfact[n-r]%MOD;
}


void solve(){

//-------------INPUT-------------
    ll n; 
    cin >> n;
    ll k;
    cin >> k;
    vll v(n);
    input(v);
    ll count=0;
    f0(i,n)
    {
        if(v[i]==1)
        {
            count++;
        }
    }
    ll zero = n-count;
    ll ans=0;

    for(ll i=k/2 +1;i<=k;i++)
    {
        if(count<i)
        {
            break;
        }
        ans +=(ncr(count,i)*ncr(zero,k-i))%MOD;

        ans%=MOD;
    }
    cout << ans%MOD << endl;



    


//-------------CODE--------------
    


}


int main(){
    fact[0]=1;
    for(ll i=1;i<=MAXN;i++)
    {
        fact[i] = fact[i-1]*i % MOD;
    }
    // compute inverse factorials using Fermat's Little Theorem
    invfact[MAXN] = binexpo(fact[MAXN], MOD-2);
    for(ll i=MAXN-1;i>=0;i--)
    {
        invfact[i]= (invfact[i+1]*(i+1))%MOD;
    }
    int tt; cin >> tt; while(tt--)
{solve();};
}
