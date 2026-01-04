/*
Problem: Number of Pairs
Link: https://codeforces.com/problemset/problem/1538/C
Author: Krishna200608

/*
Short Problem Statement:
Given an array a, count the number of pairs (i, j) such that i < j
and the sum a[i] + a[j] lies in the range [l, r].

Approach:
Sort the array to enable efficient range queries.
Fix one element a[i] at a time.
For the fixed a[i], find all indices j > i such that:
    l - a[i] <= a[j] <= r - a[i]
Use lower_bound to get the first position with value >= (l - a[i]).
Use upper_bound to get the first position with value > (r - a[i]).
The difference between these two positions gives the count of valid j
for the current i.
Accumulate this count for all i.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/


/*
Submission Link: 
https://codeforces.com/contest/1538/submission/356173231
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define in(a) for(int i = 0; i<a.size(); i++) cin>>a[i];
typedef vector<int> vi;

void solve() {
    int n;
    ll l, r;
    cin >> n >>l >> r;

    vi a(n);
    in(a);
    
    
    sort(a.begin(), a.end());
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        auto st = lower_bound(a.begin() + i + 1, a.end(), l - a[i]);
        auto e = upper_bound(a.begin() + i + 1, a.end(), r - a[i]);
        
        ans += (e - st);
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

