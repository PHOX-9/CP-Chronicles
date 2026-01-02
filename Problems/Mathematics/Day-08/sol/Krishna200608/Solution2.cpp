/*
Problem: Expected Median
Link: https://codeforces.com/problemset/problem/1999/F
Author: Krishna Sikheriya (Krishna200608)

Short Problem Statement:
Given a binary array a of length n, Arul takes all subsequences of length k (k is odd).
Find the sum of medians of all these subsequences modulo 10^9 + 7.
Since the array is binary, the median is either 0 or 1.

Approach:
1. In a binary array, the median of a subsequence of odd length k is 1 if and only if
   the count of 1s in the subsequence is at least (k + 1) / 2. Otherwise, it is 0.
2. Since we need the sum of medians, we simply need to count how many subsequences have 
   median 1 (since median 0 contributes nothing to the sum).
3. Let total_ones be the count of 1s in the array, and total_zeros be n - total_ones.
4. We need to choose exactly k elements to form a subsequence.
   Let i be the number of 1s chosen. We must choose (k - i) zeros.
5. The condition for median 1 is: i >= (k + 1) / 2.
6. The number of ways to form such a subsequence for a fixed i is:
   Ways(i) = nCr(total_ones, i) * nCr(total_zeros, k - i).
7. We iterate i from (k + 1) / 2 up to min(k, total_ones) and sum the ways modulo 10^9 + 7.
8. We use precomputed factorials and modular inverse to compute nCr efficiently.

Time Complexity: O(N) due to precomputing factorials. Each test case takes O(K) which is <= O(N).
Space Complexity: O(N) to store factorials.

Example I/O:
Input:
5 1
1 1 1 1 1
Output:
5
*/

#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1e9 + 7;
const int MAXN = 200005;

vector<long long> fact(MAXN);
vector<long long> invFact(MAXN);

// Function to compute modular exponentiation: (base^exp) % mod
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Function to compute modular inverse
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// nCr calculation
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    int ones = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val == 1) ones++;
    }
    
    int zeros = n - ones;
    int min_ones_needed = (k + 1) / 2;
    
    long long total_sum = 0;

    // Iterate through possible counts of 1s in the subsequence
    // We need at least min_ones_needed 1s
    // We can pick at most 'ones' (total available) and at most 'k' (subsequence size)
    for (int i = min_ones_needed; i <= k; ++i) {
        // If we pick i ones, we need (k - i) zeros
        int zeros_needed = k - i;
        
        if (i <= ones && zeros_needed <= zeros && zeros_needed >= 0) {
            long long ways = (nCr(ones, i) * nCr(zeros, zeros_needed)) % MOD;
            total_sum = (total_sum + ways) % MOD;
        }
    }

    cout << total_sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

/*
SUBMISSION LINK:
https://codeforces.com/contest/1999/submission/356145308
*/