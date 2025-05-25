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
    n, m, a, b = getlist()
    # print(n, m, a, b)
    ans = 1
    # while n * m > 1:
    for _ in range(1):
        o1 = (a * m, a, m)
        o2 = (n * b, n, b)
        o3 = ((n-a+1) * m, n-a+1, m)
        o4 = (n * (m-b+1), n, m-b+1)
        os = [o1, o2, o3, o4]
        n, m = min(os)[1], min(os)[2]

        a, b = (n+1) // 2, (m+1) // 2
        # print(n, m, a, b)
        # ans += 1
    ans += math.ceil(math.log2(n)) + math.ceil(math.log2(m))
    print(ans)

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
