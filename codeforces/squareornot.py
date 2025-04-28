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
    s = list(map(int, input()))
    r = int(math.sqrt(n))
    if r ** 2 == n:
        grid = [[]]
        for x in s:
            if len(grid[-1]) == r: grid.append([])
            grid[-1].append(x)
        flag = 1
        edge = lambda i, j: i == 0 or i == r-1 or j == 0 or j == r-1
        for i in range(r):
            for j in range(r):
                if edge(i, j) and grid[i][j] == 0:
                    flag = 0
                elif not edge(i, j) and grid[i][j]:
                    flag = 0
        print("YES" if flag else "NO")
    else: print("NO")

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
