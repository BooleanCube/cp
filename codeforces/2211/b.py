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
MAXN = int(2e5 + 5)
INF = 1e20
EPS = 1e-9

input = lambda : sys.stdin.readline().strip()
print = lambda *args : sys.stdout.write(" ".join(map(str, args)) + "\n")
write = lambda *args : sys.stdout.write(" ".join(map(str, args)))

getint = lambda : int(input())
getlist = lambda : list(map(int, input().split()))
getstr = lambda : list(input()) # mutable string

divs = [0] * (MAXN + 1)

for i in range(1, MAXN + 1):
    for j in range(i, MAXN, i):
        divs[j] += 1

def solve():
    x, y = getlist()
    if x - y == 0:
        print(1)
        print(*([1] * x + [-1] * y))
        return
    ans = divs[abs(x - y)]
    print(ans)
    print(*([1] * x + [-1] * y))

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()

