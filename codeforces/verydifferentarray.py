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
    n, m = getlist()
    a, c = getlist(), getlist()
    a.sort(); c.sort(reverse=True)
    pref, suff = [0]*(m+1), [0]*(m+1)
    for i in range(1, m+1):
        pref[i] = pref[i-1] + c[i-1]
        suff[-i-1] = suff[-i] + c[-i]
    ps, ss = 0, sum(a)
    ans = 0
    for i in range(n+1):
        pc, sc = i, (m-n)+i
        diff = abs(ps-pref[pc]) + abs(ss-suff[sc])
        if i<n:
            ps += a[i]
            ss -= a[i]
        ans = max(ans, diff)
    print(ans)

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
