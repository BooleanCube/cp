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

sys.setrecursionlimit(int(2e5))

input = lambda : sys.stdin.readline().strip()
print = lambda *args : sys.stdout.write(" ".join(map(str, args)) + "\n")
write = lambda *args : sys.stdout.write(" ".join(map(str, args)))

getint = lambda : int(input())
getlist = lambda : list(map(int, input().split()))
getstr = lambda : list(input()) # mutable string

def findloop(memo, vis, p, b, idx):
    if memo[idx] != -1: return memo[idx]
    if idx in vis:
        cur, cnt = p[idx], b[idx]
        while cur != idx:
            cnt += b[cur]
            cur = p[cur]
        cur = p[idx]
        memo[idx] = cnt
        while cur != idx:
            memo[cur] = cnt
            cur = p[cur]
        return
    vis.add(idx)
    findloop(memo, vis, p, b, p[idx])

def check(memo, p, b, idx):
    if memo[idx] != -1: return memo[idx]
    memo[idx] = b[idx] + check(memo, p, b, p[idx])
    return memo[idx]

def solve():
    n = getint()
    p = [x - 1 for x in getlist()]
    b = [x ^ 1 for x in list(map(int, input()))]
    memo = [-1] * n
    for i in range(n):
        if i == p[i]:
            memo[i] = b[i]
            continue
        findloop(memo, set(), p, b, i)
        check(memo, p, b, i)
    print(*memo)
    

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
