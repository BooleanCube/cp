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
    if a + b > n:
        print("NO")
        return
    f = list(range(1, n+1))
    s = list(range(1, n+1))
    c = 0
    while min(a, b) > 1:
        a -= 1; b -= 1
        s[c], s[c+1] = s[c+1], s[c]
        c += 2
    if min(a, b) == 0 and max(a, b):
        print("NO")
        return
    rem = max(a, b)
    if a == rem: f.insert(c+rem, f.pop(c))
    else: rem = s.insert(c+rem, s.pop(c))
    print("YES")
    print(*f)
    print(*s)

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
