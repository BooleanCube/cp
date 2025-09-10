from math import atan2

n = int(input())
pts = [tuple(map(int, input().split())) for _ in range(n)]

area = 0

for i in range(n):
    p1, p2 = pts[i], pts[(i+1)%n]
    area += p1[0]*p2[1] - p2[0]*p1[1]

print(abs(area))
