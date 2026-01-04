//submission: https://codeforces.com/problemset/submission/1999/356309382
// P.S.: Given a binary array arr of length n and an  integer k. Need to 
// find sum of median of all subsequences of arr. Ans. should be modulo 1e9+7

#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const int MOD = 1e9+7;
// The precomputation is O(N) and each test case is O(K)
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

const int MAX = 200005;
ll fact[MAX], invFact[MAX];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) fact[i] = (fact[i - 1] * i) % MOD;
    invFact[MAX - 1] = modInverse(fact[MAX - 1]);
    for (int i = MAX - 2; i >= 0; i--) invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    ll num = fact[n];
    ll den = (invFact[r] * invFact[n - r]) % MOD;
    return (num * den) % MOD;
}

void solve() {
    int n, k;
    cin>>n>>k;
    int c1 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) c1++;
    }
    int c0 = n - c1;

    ll ans = 0;
    int min_ones = (k + 1) / 2;

    // Median is 1 if we pick i ones where i >= (k+1)/2
    for (int i = min_ones; i <= k; i++) {
        if (i <= c1 && (k - i) <= c0) {
            ll ways = (nCr(c1, i) * nCr(c0, k - i)) % MOD;
            ans = (ans + ways) % MOD;
        }
    }
    cout << ans << "\n";
}
// T.C.: O(MAX+T*K)
// S.C.: O(MAX)

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
