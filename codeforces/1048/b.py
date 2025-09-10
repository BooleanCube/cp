def solve():
    n, m = map(int, input().split())
    a = sorted(map(int, input().split()))[::-1]
    ans = 0
    for i in range(min(n, m)):
        ans += a[i] * m
        m -= 1
    print(ans)


tc = int(input())
while tc:
    tc -= 1
    solve()
