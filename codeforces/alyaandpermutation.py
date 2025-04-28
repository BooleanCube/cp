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
    p2 = set([2 ** i for i in range(32)])
    n = getint()
    l = []
    if n & 1:
        l = list(range(2, n - 1)) + [1, n-1, n]
    elif n in p2:
        l = list(range(2, n - 2)) + [1, n-2, n-1, n]
    else:
        p = 2 ** int(math.log2(n))
        l = (list(range(1, p-1)) + list(range(p, n-1))) + [n, n-1, p-1]
    k = 0
    for i in range(n):
        if (i+1) & 1: k &= l[i]
        else: k |= l[i]
    print(k)
    print(*l)

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
