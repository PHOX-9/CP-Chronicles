/*
DAY 8
Q1 B. Sasha and the Apartment Purchase

*/
/*
Sort the bar positions. Since at most k bars can close, exactly n−k bars will remain.
For this many bars, the optimal apartment must lie between the symmetric medians of the remaining bars.
The answer is simply the size of that interval: v[right] - v[left] + 1.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end());

        int m = n - k;
        int left = (m - 1) / 2;
        int right = n - 1 - left;

        cout << v[right] - v[left] + 1 << "\n";
    }
    return 0;
}


//Tc =O(nlogn)  SC = O(n)
/*
My submission : https://codeforces.com/contest/2098/submission/356286079
*/