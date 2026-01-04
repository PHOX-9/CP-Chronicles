/*

Submission Link: https://codeforces.com/contest/1999/submission/356144535

count the num of ones, and zeroes in the binary string, and we have to get the substrings with middle element one
so.. we want majority (k+1)/2 ones
so, we iterate over the minimum ones we want, to max possible - max(k, onesAvaiable), and do n choose r

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 10, MOD = 1e9 + 7;

vector<ll> fact(N);

ll power(ll a, ll b) {
    a %= MOD;
    ll ans = 1;
    while (b > 0) {
        if (b % 2 == 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return ans;
}

ll inverse(ll n) {
    return power(n, MOD - 2);
}

ll C(ll n, ll r) {
    if (n < r) return 0;
    return fact[n] * inverse((fact[n - r] * fact[r]) % MOD) % MOD;
}


ll solve(int n, int k, int o, int z) {

    // cout << n << k << o << z;
    
    // 0 0 1 1
    int minOne = (k+1)/2;
    int maxOne = min(o, k);

    ll ans = 0;
    for (int oneCnt = minOne; oneCnt <= maxOne; oneCnt++) {
        int zeroCnt = k - oneCnt;
        ans = (ans + (C(z, zeroCnt) * 1LL * C(o, oneCnt)) % MOD) % MOD;
    }

    return ans;

}

int main() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ones = 0, zeroes = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            if (temp == 0) zeroes++;
            else ones++;
        }
        
        cout << solve(n, k, ones, zeroes) << endl;
    }
}