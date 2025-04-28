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
    s = input()
    z, o = [1], deque()
    for i in range(1, n):
        if s[i] == '0': z.append(i + 1)
        else: o.append(i + 1)
    ans = 0
    while o:
        cur = o.pop()
        if z:
            while z and z[-1] > cur: ans += z.pop(-1)
            if z: ans += z.pop(-1)
        elif o: ans += o.popleft()
        else: ans += cur
    ans += sum(z)
    print(ans)

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
