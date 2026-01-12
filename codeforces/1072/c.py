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
    n, k = getlist()
    q = deque([(n, 0)])
    vis = set([n])
    rc = set([n])
    while q:
        sz, dp = q.popleft()
        left = sz // 2
        right = (sz + 1) // 2
        if left not in vis:
            vis.add(left)

            nrc = set()
            for r in rc:
                nrc.add(r)
                if r == sz: nrc.add(left)
            rc.update(nrc)

            if k in rc: return dp + 1

            if left > k: q.append((left, dp + 1))
        if right not in vis:
            vis.add(right)

            nrc = set()
            for r in rc:
                nrc.add(r)
                if r == sz: nrc.add(right)
            rc.update(nrc)

            if k in rc: return dp + 1

            if right > k: q.append((right, dp + 1))
    return -1


testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    print(solve())

