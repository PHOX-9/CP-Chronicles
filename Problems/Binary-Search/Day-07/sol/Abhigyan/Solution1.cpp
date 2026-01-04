// https://codeforces.com/contest/1538/submission/356243914
// Given an array of n integers,find all pairs (ai,aj): i<j where  l≤ai+aj≤r

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7; 
const ll INF = 1e18;

void solve() {
    ll n,l,r;
    cin>>n>>l>>r;
    vector<ll> a(n);
    for(auto &x: a) cin>>x;
    //sort the array for Binary search
    sort(all(a));
    ll prs=0;
    //first find all pairs A with sum <= r then those pairs B with sum less than l
    for(int i=0;i<n;i++){
        int p =upper_bound(all(a),r-a[i])-a.begin();
        int q =upper_bound(all(a),l-1-a[i])-a.begin();
        prs+=p-1; prs-=q-1;
        if(a[i]+a[i]>=l && a[i]+a[i]<=r) prs--; //to remove self pair e.g. (ai,ai) absurd
    }
    //ans is (A-B)/2, divided by 2 to remove repeated pairs as order doesn't matter
    cout<<prs/2<<endl;
}
// T.C.: O(n*logn); S.C.: O(1)
int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
