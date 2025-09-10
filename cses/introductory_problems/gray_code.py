n = int(input())
cnt = 1 << n
ans = [bin(i^(i>>1))[2:] for i in range(cnt)]
for row in ans: print(row.zfill(n))