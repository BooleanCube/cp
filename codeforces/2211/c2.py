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

    fqa, fqb = Counter(a[:k]), Counter(b[:k])
    for x in fqa:
        used = min(fqa[x], fqb[x])
        fqa[x] -= used
        fqb[x] -= used
    if sum(fqa.values()) != fqb[-1] or sum(fqb.values()) != fqb[-1]:
        print("NO")
        return

    for i in range(k):
        fqa, fqb = Counter(a[i::k]), Counter(b[i::k])
        if len(fqa) > 1:
            for j in range(i, n, k):
                if a[j] != b[j] and b[j] != -1:
                    print("NO")
                    return
        elif len(fqb) - int(-1 in fqb) > 1:
            print("NO")
            return

    print("YES")


testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()

