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
    a = getlist()
    ra = a[::-1]
    suffmx, prefsm = [a[0]], [ra[0]]
    for i in range(1, n):
        suffmx.append(max(suffmx[-1], a[i]))
        prefsm.append(prefsm[-1] + ra[i])
    suffmx.reverse()
    # print(suffmx)
    # print(prefsm)
    ans = [suffmx[0]]
    for i in range(1, n):
        ans.append(prefsm[i - 1] + suffmx[i])
    print(*ans)

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
