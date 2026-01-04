"""
Approach: solution with on-demand computation
Submission Link: https://codeforces.com/problemset/submission/1999/356145876"""

MOD = 10**9 + 7

def mod_inverse(a, m=MOD):
    return pow(a, m - 2, m)

def nCr_direct(n, r):
    if r < 0 or r > n:
        return 0
    if r == 0 or r == n:
        return 1
    
    numerator = 1
    for i in range(r):
        numerator = (numerator * (n - i)) % MOD
    
    denominator = 1
    for i in range(1, r + 1):
        denominator = (denominator * i) % MOD
    
    return (numerator * mod_inverse(denominator)) % MOD

def solve_alt():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    ones = sum(a)
    zeros = n - ones
    
    min_ones = k // 2 + 1
    answer = 0
    
    for ones_req in range(min_ones, min(k, ones) + 1):
        zeros_req = k - ones_req
        if zeros_req > zeros:
            continue
        
        ways = (nCr_direct(ones, ones_req) * nCr_direct(zeros, zeros_req)) % MOD
        answer = (answer + ways) % MOD
    
    print(answer)

t = int(input())
for _ in range(t):
    solve_alt()
