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
    if n == 1 and x == 0:
        print(-1)
        return
    b = bin(x)[2:][::-1]
    ans, mns, rem = 0, [], n
    for i in range(len(b)):
        if b[i] == "0": mns.append(i)
        else:
            ans += 1 << i
            rem -= 1
            rem = max(rem, 0)
    anss = []
    for i in range(len(b) + 1):
        rem = n - i
        if x > 0 and i < 1: continue
        if i > b.count("1"): break
        if i > n: break
        cur = ans
        if rem == 1 and b[0] == "0": cur += 2
        elif rem == 1 and b[0] == "1": cur += 4
        elif rem & 1: cur += (rem - 1) + 4
        else: cur += rem
        anss.append(cur)
    # print(ans, rem, mns, b)
    
    print(min(anss))

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    #write(f"Case {c}: ")
    solve()
