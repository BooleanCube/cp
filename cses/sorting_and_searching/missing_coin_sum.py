import sys
n = int(sys.stdin.readline())
l = list(map(int, sys.stdin.readline().split()))
l.sort()
cs = 1
i = 0
while i<n and cs>=l[i]:
    cs += l[i]
    i += 1
print(cs)