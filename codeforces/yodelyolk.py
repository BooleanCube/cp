import random
import math
from collections import defaultdict, Counter, deque, OrderedDict
from queue import PriorityQueue
from heapq import heapify, heappush, heappop
from functools import lru_cache, reduce
from bisect import bisect_left, bisect_right
from types import GeneratorType
import sys

MOD = 10**9+7
HMOD = 998244353
MAXN = 10**5+5
INF = 1e20
EPS = 1e-9

input = lambda : sys.stdin.readline().strip()
print = lambda *args : sys.stdout.write(" ".join(map(str, args)) + "\n")
write = lambda *args : sys.stdout.write(" ".join(map(str, args)))

getint = lambda : int(input())
getlist = lambda : list(map(int, input().split()))
getstr = lambda : list(input()) # mutable string

def solve():
    n = getint()
    h = getlist()
    l, r = 0, 0
    ans = 0
    while l < n:
        r = l + 1
        while r < n and h[r] < h[l]: r += 1
        if r == n: break
        ans = max(ans, sum(max(0, min(h[l], h[r]) - h[i]) for i in range(l+1, r)))
        l = r
    l, r = n-1, n-1
    while r >= 0:
        l = r - 1
        while l >= 0 and h[l] < h[r]: l -= 1
        if l == -1: break
        ans = max(ans, sum(max(0, min(h[l], h[r]) - h[i]) for i in range(l+1, r)))
        r = l
    print(ans)

testcases = 1
#testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
