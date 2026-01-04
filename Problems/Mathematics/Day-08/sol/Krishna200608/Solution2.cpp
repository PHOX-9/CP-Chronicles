/*
Problem: Expected Median
Link: https://codeforces.com/problemset/problem/1999/F
Author: Krishna200608

Short Problem Statement:
Calculate the sum of medians of all subsequences of length k from a binary array.
Result modulo 1e9+7.

Approach:
    Since the array has only 0s and 1s, the median is 1 if count(1s) >= (k+1)/2 in the subsequence.
    Otherwise, median is 0 and doesn't contribute to sum.
    Count total 1s (c1) and 0s (c0) in input.
    Iterate i (number of 1s picked) from (k+1)/2 to k.
    Add nCr(c1, i) * nCr(c0, k-i) to answer.
    Use precomputed factorials for nCr.

Time Complexity: O(N)
Space Complexity: O(N)
*/

/*
SUBMISSION LINK:
https://codeforces.com/contest/1999/submission/356178663
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int MX = 200005;

ll f[MX], invf[MX];

ll pw(ll a, ll e) {
    ll r = 1;
    a %= MOD;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

ll inv(ll x) {
    return pw(x, MOD - 2);
}

void pre() {
    f[0] = invf[0] = 1;
    for (int i = 1; i < MX; i++) f[i] = (f[i - 1] * i) % MOD;
    invf[MX - 1] = inv(f[MX - 1]);
    for (int i = MX - 2; i >= 1; i--)
        invf[i] = (invf[i + 1] * (i + 1)) % MOD;
}

ll C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return f[n] * invf[r] % MOD * invf[n - r] % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int o = 0;
    for (ll x : a) if (x == 1) o++;
    int z = n - o;

    int mn = (k + 1) / 2;
    ll res = 0;

    for (int i = mn; i <= k; i++) {
        int j = k - i;
        res = (res + C(o, i) * C(z, j)) % MOD;
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pre();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}


