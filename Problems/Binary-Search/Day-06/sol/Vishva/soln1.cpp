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


// submission link:- https://codeforces.com/contest/2014/submission/356192778



void solve(){

//-------------INPUT-------------
    ll n; 
    cin >> n;
    vll v(n);
    ll sum=0;

    input(v);
    f0(i,n){
        sum+=v[i];
    }
    sort(all(v));
    // i will sort this and pick the middle one to check
    if(n<3)
    {
        cout << -1 << endl;
        return;
    }
    // formulated here 
    ll ans = 2*v[n/2]*n-sum+1;

    cout << max(0LL,ans) << endl;

  //time conplexity is simple o(n) here 
  // robin needs to appear by all chance then x==0 else 




//-------------CODE--------------
    


}


int main(){
    int tt; cin >> tt; while(tt--)
{solve();};
}
