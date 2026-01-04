
/*
Submission Link : https://codeforces.com/contest/2098/submission/356191201

Tc - O(n log n) 

Sc - O(n)


Approach : 
First, sort all the bar positions.
A range of medians is possible only when we pick an even number of bars.
If we pick an odd number, the median becomes just one single position, not a range.
So, to get the maximum number of median positions, we always try to pick an even-sized group.
If n - k is even, we use all those bars.
If n - k is odd, we remove one more bar to make the count even.
After fixing the size m, the possible median positions lie between
index (m/2 - 1) and index (n - m/2) in the sorted list.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int m = n - k;
    int left_idx = (m + 1) / 2 - 1;
    int right_idx = k + (m / 2);

    long long result = (long long)a[right_idx] - a[left_idx] + 1;
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}