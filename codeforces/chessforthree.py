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
    a, b, c = getlist()
    if (a+b+c) & 1:
        print(-1)
        return
    l = [a, b, c]
    while l and l[0] == 0: l.pop(0)
    ans = 0
    while len(l) > 1:
        ans += 1
        l[0] -= 1
        if l[0] == 0: l.pop(0)
        l[-1] -= 1
        if l[-1] == 0: l.pop(-1)
        l.sort()
    print(ans)

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
