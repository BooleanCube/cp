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
    p = [0] + getlist()
    idxmp = [0]*(n+1)
    for i in range(1, 1+n): idxmp[p[i]] = i
    ans = 0
    for i in range(1, 1+n):
        if p[i] == i: continue
        if p[p[i]] == i: continue
        cidx = idxmp[i]
        idxmp[i], idxmp[p[p[i]]] = idxmp[p[p[i]]], idxmp[i]
        p[p[i]], p[cidx] = p[cidx], p[p[i]]
        # print(i, p, idxmp)
        ans += 1
    print(ans)

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
