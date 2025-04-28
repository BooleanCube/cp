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

def good(a, k):
    n = len(a)
    c = []
    for i in range(1, n-1):
        d1 = a[i] - a[i-1]
        d2 = a[i+1] - a[i]
        # print(d1, d2)
        if d1 > k and d2 > k: c.append(a[i])
    if len(c) == 2 and c[1] - c[0] <= 2 * k: return 1
    return len(c) < 2

def solve():
    n = getint()
    a = sorted(getlist())
    a = [-INF] + a + [INF]
    lo, hi = 1, int(1e18)
    while lo < hi:
        mid = (lo + hi) // 2
        if good(a, mid): hi = mid
        else: lo = mid + 1
    print(lo)

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
