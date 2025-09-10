import sys
from math import floor, ceil

n = int(input())
l = list(map(int, input().split()))

poss = set()

c = 0
def backtrack(idx):
    global c, n
    if idx == n:
        poss.add(c)
        return 0
    
    c += l[idx]
    backtrack(idx+1)
    c -= l[idx]
    backtrack(idx+1)

backtrack(0)

center, ans = sum(l)/2, 1e20
for i in poss:
    ans = min(ans, round(2*abs(center-i)))

print(ans)