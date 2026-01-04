"""
Problem: C. Number of Pairs
Link: https://codeforces.com/problemset/problem/1538/C

Short Problem Statement:
Given an array of integers, count the number of index pairs (i, j)
such that i < j and the sum a[i] + a[j] lies between l and r (inclusive).

Approach:
- Sort the array.
- For each index i, we want to find how many indices j > i satisfy:
    l - a[i] <= a[j] <= r - a[i]
- Since the array is sorted, binary search can be used to find
  the valid range of j efficiently.
- Sum the counts for all i.

Time Complexity:
O(n log n) per test case

Space Complexity:
O(n)

Example:
Input:
3 4 7
5 1 2

Output:
2

Submission Link:
https://codeforces.com/contest/1538/submission/356210806
"""

import sys
from bisect import bisect_left, bisect_right

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n, l, r = map(int, input().split())
    a = list(map(int, input().split()))

    a.sort()
    ans = 0

    for i in range(n):
        left = bisect_left(a, l - a[i], i + 1)
        right = bisect_right(a, r - a[i], i + 1)
        ans += (right - left)

    print(ans)
