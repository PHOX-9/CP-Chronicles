import java.util.*;
import java.io.*;

public class Solution2 {
    static long[] fact, invFact;
    static final int MOD = 1_000_000_007;
    static final int MAX = 200_005;

    public static void main(String[] args) throws IOException {
        precompute();
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        StringBuilder sb = new StringBuilder();

        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();

            int c1 = 0;
            for (int i = 0; i < n; i++) {
                if (sc.nextInt() == 1) c1++;
            }
            int c0 = n - c1;

            long ans = 0;
            int minOnes = (k + 1) / 2;

            for (int i = minOnes; i <= Math.min(k, c1); i++) {
                int zerosNeeded = k - i;
                if (zerosNeeded <= c0) {
                    long ways = (nCr(c1, i) * nCr(c0, zerosNeeded)) % MOD;
                    ans = (ans + ways) % MOD;
                }
            }
            sb.append(ans).append("\n");
        }
        System.out.print(sb);
    }

    static void precompute() {
        fact = new long[MAX];
        invFact = new long[MAX];
        fact[0] = 1;
        for (int i = 1; i < MAX; i++) fact[i] = (fact[i - 1] * i) % MOD;
        invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
        for (int i = MAX - 2; i >= 0; i--)
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }

    static long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }

    static long power(long base, long exp) {
        long res = 1;
        base %= MOD;
        while (exp > 0) {
            if ((exp & 1) == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    static class FastReader {
        StringTokenizer st;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    return null;
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }
    }
}

/*
-------------------- SIMPLE DOCUMENTATION --------------------

What this code does:
- For each test case, it counts the number of valid ways to choose
  exactly k elements from an array of 0s and 1s.

Key condition:
- The chosen k elements must contain STRICTLY more 1s than 0s.
  That means number of 1s >= (k + 1) / 2.

How it works:
1) Count total number of 1s (c1) and 0s (c0)
2) Try all valid counts of 1s from:
      minOnes = (k + 1) / 2  up to min(k, c1)
3) For each choice:
      - choose i ones from c1
      - choose (k - i) zeros from c0
4) Add all combinations using nCr

Why combinations:
- Order does not matter
- We are just choosing positions

Why precomputation:
- Factorials and inverse factorials are precomputed
- This makes nCr calculation O(1)

Math used:
- Modular arithmetic with MOD = 1e9 + 7
- Fermat’s Little Theorem for inverse

Time Complexity:
- Precompute: O(MAX)
- Per test case: O(n + k)

Submission:
https://codeforces.com/contest/1999/submission/356146700
----------------------------------------------------------
*/

