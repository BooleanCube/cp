n, x = map(int, input().split())
l = sorted(map(int, input().split()))
lp, rp, ans = 0, n-1, 0
while lp <= rp:
    if lp == rp:
        ans += 1
        break
    if l[lp]+l[rp] > x:
        ans += 1
        rp -= 1
    else:
        ans += 1
        lp += 1; rp -= 1
print(ans)