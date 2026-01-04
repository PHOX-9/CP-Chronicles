//Submission Link: https://codeforces.com/contest/1999/submission/356264212

/*
First I counted the number of one and zeros then I calculated the permutation possible for getting k element using one or zero. THen by
applying pnc calculated the number of subsequences.
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
 
const long long mod=1e9+7;
 
vector<long long> fact(200001);
 
long long binexp(long long a, long long b) {
    long long ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans%mod;
}
 
long long C(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    long long ans=fact[n] * binexp(fact[r], mod - 2) % mod;
    ans*=binexp(fact[n - r], mod - 2) % mod;
    return ans%mod;
}

int main() {
    fastio;
    fact[0]=1;
    for(long long i=1; i<200001; i++) fact[i]=(fact[i-1]*i)%mod;
    long long t;
    cin>>t;
    while(t--) {
        long long n, k;
        cin>>n>>k;
        vector<int> a(n), cnt(2,0);
        for(int i=0; i<n; i++) {
            cin>>a[i];
            cnt[a[i]]++;
        }
        long long ans=0;
        for(long long i=0; i<=cnt[0]; i++) {
            int b=k-i;
            if(b>=0 && b<=cnt[1]) {
                if(b>i) ans+=(C(cnt[0], i)%mod)*(C(cnt[1], b)%mod)%mod;
            }
        }
        cout<<ans%mod<<endl;
    }
}
