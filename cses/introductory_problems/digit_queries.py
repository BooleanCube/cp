import sys
from math import floor, ceil, log10

N = int(1e2)
last = {1:1, 9:9}
c = 10
for i in range(20):
    last[c] = last[c-1] + int(log10(c))+1
    nc = c*10-1
    last[nc] = last[c] + (nc-c)*(int(log10(c))+1)
    c *= 10

keys = [10**i-1 for i in range(1,20)]
q = int(input())
for _ in range(q):
    k = int(input())
    l = 0
    for i in keys:
        l = i
        if last[i] >= k: break
    s, e = (l+1)//10, l
    # print("start", k, s, e)
    b, dlen = s, (int(log10(s))+1)
    while s < e:
        m = s+((e-s)>>1)
        num = last[b] + (m-b)*dlen
        if num-dlen+1 == k: e = m; break
        elif num-dlen+1 > k: e = m-1
        else: s = m+1
    while (last[b] + (e-b)*dlen)-k >= dlen: e -= 1
    while (last[b] + (e-b)*dlen)-k < 0: e += 1
    num = last[b] + (e-b)*dlen
    # print(num, k, e)
    print(str(e)[::-1][num-k])
