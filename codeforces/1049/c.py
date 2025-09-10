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

def calc(n, a, i, j):
    a[i], a[j] = a[j], a[i]
    ans = 0
    for x in range(1, 1+n): ans += (2 * (x & 1) - 1) * a[x-1]
    a[i], a[j] = a[j], a[i]
    return ans + abs(j - i)

def solve():
    n = getint()
    a = getlist()
    if n == 1:
        print(a[0])
        return

    ans = max(calc(n, a, 0, n-1), calc(n, a, 0, n-2), calc(n, a, 1, n-1))

    mxo = max(a[i] for i in range(1, n, 2))
    mne = min(a[i] for i in range(0, n, 2))
    mxs = [i for i in range(1, n, 2) if a[i] == mxo]
    mns = [i for i in range(0, n, 2) if a[i] == mne]
    mxs = [mxs[0], mxs[-1]]
    mns = [mns[0], mns[-1]]
    for mxidx in mxs:
        for mnidx in mns:
            ans = max(ans, calc(n, a, mxidx, mnidx))
    for idx in mxs: ans = max(ans, calc(n, a, idx, 0), calc(n, a, idx, n-1), calc(n, a, idx, n-2))
    for idx in mns: ans = max(ans, calc(n, a, idx, 0), calc(n, a, idx, n-1), calc(n, a, idx, n-2))

    mxe = max(a[i] for i in range(0, n, 2))
    mno = min(a[i] for i in range(1, n, 2))
    mxs = [i for i in range(0, n, 2) if a[i] == mxe]
    mns = [i for i in range(1, n, 2) if a[i] == mno]
    mxs = [mxs[0], mxs[-1]]
    mns = [mns[0], mns[-1]]
    for mxidx in mxs:
        for mnidx in mns:
            ans = max(ans, calc(n, a, mxidx, mnidx))
    for idx in mxs: ans = max(ans, calc(n, a, idx, 0), calc(n, a, idx, n-1), calc(n, a, idx, n-2))
    for idx in mns: ans = max(ans, calc(n, a, idx, 0), calc(n, a, idx, n-1), calc(n, a, idx, n-2))

    print(ans)

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {{c}}: ")
    solve()
