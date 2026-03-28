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


def solve():
    n, k = getlist()
    a = getlist()
    b = getlist()
    for i in list(range(n-k)) + list(range(k, n)):
        if b[i] != -1 and b[i] != a[i]:
            print("NO")
            return
    l, r = n-k, k
    fqa, fqb = Counter(a[l:r]), Counter(b[l:r])
    # print(fqa, fqb)
    for x in fqa:
        if x == -1: continue
        used = min(fqa[x], fqb[x])
        fqa[x] -= used
        fqb[x] -= used
    # print(fqa, fqb)
    if sum(fqa.values()) - fqa[-1] != fqb[-1] or sum(fqb.values()) - fqb[-1] != fqa[-1]:
        print("NO")
        return
    print("YES")
    

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()

