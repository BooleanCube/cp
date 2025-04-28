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
    n, r = getlist()
    a = getlist()
    a.sort(key=lambda x: x&1)
    seats = r * 2
    sa = sum(a)
    se, so = sum(x for x in a if x % 2 == 0), sum(x for x in a if x & 1)
    cnto = sum((x + 1) // 2 for x in a if x & 1)
    odds = []
    for i in range(n):
        x = a[i]
        if x % 2 == 0: continue
        while x > 1:
            odds.append(2)
            x -= 2
        odds.append(1)
    extra = sum(odds[(seats - se) // 2:])
    within = sum(odds[:(seats - se) // 2])
    print(se + within - extra)

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
