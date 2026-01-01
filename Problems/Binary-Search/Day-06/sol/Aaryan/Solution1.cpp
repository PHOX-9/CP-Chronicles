// link : https://codeforces.com/contest/2014/submission/356025598

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (n <= 2) {
        cout << -1 << "\n";
        return;
    }

    sort(a.begin(), a.end());

    ll l = 0, r = 1e18, ans = -1;

    while (l <= r) {
        ll mid = (l + r) / 2;

        long double avg = (long double)(sum + mid) / n;
        long double half = avg / 2.0;

        int cnt = 0;
        for (ll v : a) {
            if ((long double)v < half)
                cnt++;
        }

        if (cnt > n / 2) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}


/*
Approach:
We are allowed to add a non-negative value x to the total sum of the array.
After adding x, let the new average be:
    avg = (sum + x) / n
We want more than half of the elements to be strictly less than:
    avg / 2
If n <= 2, this is impossible, so we directly output -1.

Since adding more x only increases avg, the condition becomes monotonic.
  Hence, we can binary search the minimum x.
For a fixed x:
    * Compute avg and avg/2
    * Count how many elements are < avg/2
    * If count > n/2, the condition is satisfied.

Binary search over x in the range [0, 1e18] and keep the minimum valid x.

Time Complexity: O(n log n)

Space Complexity: O(n) 
*/
