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
    fq = defaultdict(list)
    for _ in range(n):
        l = getlist()
        fq[l[0]].append(l[1])
    print((n-2)*(n-len(fq)) + sum(1 for x in fq if (x in fq and x-1 in fq and x+1 in fq) and ((0 in fq[x] and 1 in fq[x-1] and 1 in fq[x+1]) or (1 in fq[x] and 0 in fq[x-1] and 0 in fq[x+1]))))

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
