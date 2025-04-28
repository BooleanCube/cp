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
    n, x = getlist()
    a = getlist()
    pq = PriorityQueue()
    for i in a: pq.put(-i)
    ans = 0
    while len(pq.queue):
        clen = min(len(pq.queue), x+1)
        cur = [-pq.get() for _ in range(clen)]
        if clen <= x:
            ans += cur[0]
            break
        cmin = cur.pop(-1)
        diff = cur[-1] - cmin + 1
        cur = [i - diff for i in cur if i - diff > 0]
        for i in cur: pq.put(-i)
        pq.put(-cmin)
        ans += diff
    print(ans)
        

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
