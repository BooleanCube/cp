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
    n, a, b = getlist()
    d = getstr()*1000
    ans = 0
    x, y = 0, 0
    for i in range(len(d)):
        if x == a and y == b: ans = 1
        if d[i] == "N": y += 1
        if d[i] == "W": x -= 1
        if d[i] == "S": y -= 1
        if d[i] == "E": x += 1
        if x == a and y == b: ans = 1
    print("YES" if ans else "NO")


testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
