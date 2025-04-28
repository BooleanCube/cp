import random
import math
from collections import defaultdict, Counter, deque, OrderedDict
from queue import PriorityQueue
from heapq import heapify, heappush, heappop
from functools import lru_cache, reduce
from bisect import bisect_left, bisect_right
from types import GeneratorType
import sys
from string import ascii_lowercase as alp

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
    s = getstr()
    if n & 1:
        # do the psum
        eps, ops = [(0,)*26], [(0,)*26]
        for i in range(n):
            idx = alp.find(s[i])
            if i & 1:
                cur = list(ops[-1])
                cur[idx] += 1
                ops.append(tuple(cur))
            else:
                cur = list(eps[-1])
                cur[idx] += 1
                eps.append(tuple(cur))
        ans = int(INF)
        for i in range(n):
            efq, ofq = [0]*26, [0]*26
            if i & 1:
                if i > 1:
                    for j in range(26): ofq[j] += ops[i // 2][j]
                if i > 0:
                    for j in range(26): efq[j] += eps[i // 2 + 1][j]
                if i < n - 1:
                    for j in range(26): ofq[j] += eps[-1][j] - eps[i // 2 + 1][j]
                if i < n - 2:
                    for j in range(26): efq[j] += ops[-1][j] - ops[i // 2 + 1][j]
            else:
                if i > 1:
                    for j in range(26): ofq[j] += ops[i // 2][j]
                if i > 1:
                    for j in range(26): efq[j] += eps[i // 2][j]
                if i < n - 1:
                    for j in range(26): ofq[j] += eps[-1][j] - eps[i // 2 + 1][j]
                if i < n - 1:
                    for j in range(26): efq[j] += ops[-1][j] - ops[i // 2][j]
            # print(i)
            # print(efq)
            # print(ofq)
            # print("-----------")
            ans = min(ans, sum(efq) + sum(ofq) - max(efq) - max(ofq))
        print(ans + 1)

    else:
        efq, ofq = [0]*26, [0]*26
        for i in range(n):
            if i & 1: ofq[alp.find(s[i])] += 1
            else: efq[alp.find(s[i])] += 1
        print(sum(efq) + sum(ofq) - max(efq) - max(ofq))

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
