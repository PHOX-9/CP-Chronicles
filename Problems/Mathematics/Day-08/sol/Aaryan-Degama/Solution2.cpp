// link : https://codeforces.com/problemset/submission/1999/356142534

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int MAXN = 200000;

ll fact[MAXN + 1], invfact[MAXN + 1];

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

ll C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vi a(n);
    int ones = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ones += a[i];
    }
    int zeros = n - ones;

    int need = (k + 1) / 2;
    ll ans = 0;

    for (int i = need; i <= k; i++) {
        if (i <= ones && k - i <= zeros) {
            ans = (ans + C(ones, i) * C(zeros, k - i)) % MOD;
        }
    }

    cout << ans << '\n';
}

int main() {
    fastio

    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invfact[MAXN] = modpow(fact[MAXN], MOD - 2);
    for (int i = MAXN; i >= 1; i--)
        invfact[i - 1] = invfact[i] * i % MOD;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


/*
Explaination
For odd k, the median of a binary subsequence is 1 iff it has at least (k+1)/2 ones.
So we count all subsequences of length k with >= (k+1)/2 ones.

Let ones = number of 1s, zeros = number of 0s.
Answer = sum over i = (k+1)/2 to k of:
C(ones, i) * C(zeros, k - i)

Use precomputed factorials and modular inverses.


Complexity:
Time : O(N)
Space: O(N)
*/