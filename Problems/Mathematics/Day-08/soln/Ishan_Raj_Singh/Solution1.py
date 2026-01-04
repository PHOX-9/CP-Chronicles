"""
Approach:
1. Sort the bar positions
2. Try all possible ways to keep (n-k) consecutive bars
3. For each configuration, the optimal position is the median
4. If (n-k) is odd, median is unique
5. If (n-k) is even, all positions between two middle elements are optimal
6. Collect all possible optimal positions and return count

Submission Link: https://codeforces.com/problemset/submission/2098/356145363
"""

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    a.sort()
    
    if k >= n:
        print(10**9)
        return
    
    remain = n - k
    
    houses = set()
    
    for start in range(n - remain + 1):
        end = start + remain - 1
        
        window = a[start:end + 1]
        
        mid = len(window) // 2
        
        if remain % 2 == 1:
            houses.add(window[mid])
        else:
            left_mid = window[mid - 1]
            right_mid = window[mid]
            
            for pos in range(left_mid, right_mid + 1):
                houses.add(pos)
    
    print(len(houses))

t = int(input())
for _ in range(t):
    solve()
