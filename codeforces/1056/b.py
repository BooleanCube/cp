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
    k = n ** 2 - k
    if n == 1 or k == 1:
        print("NO")
        return
    ans = [['D']*n for _ in range(n)]
    i = 0
    while k:
        if k >= n:
            ans[i] = list("RL" * (n >> 1) + "L" * (n & 1))
            k -= n
        elif k > 1:
            ans[i] = list("RL" * (k >> 1) + "L" * (k & 1)) + ans[i][k:]
            k = 0
        else:
            ans[i][0] = "U"
            k = 0
        i += 1
    print("YES")
    for row in ans: print("".join(row))

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
