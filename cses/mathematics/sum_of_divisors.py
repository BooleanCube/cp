from math import isqrt

MOD = int(1e9+7)

n = int(input())

ans, i = 0, 1
while i <= n:
    cnt = n // i
    hi = min(n, n // cnt)
    rcnt = (hi-i+1)*(i+hi)>>1
    # print(i, cnt, hi, rcnt)
    rcnt %= MOD
    sm = (cnt*rcnt) % MOD
    ans += sm
    ans %= MOD
    i = hi+1
print(ans)
