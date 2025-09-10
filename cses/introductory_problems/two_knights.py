n = int(input())
dp = [0, 0, 6, 28, 96, 252, 550]
for i in range(7, n+1):
    dp.append(5*dp[-1]-10*dp[-2]+10*dp[-3]-5*dp[-4]+dp[-5])
for k in range(1, n+1): print(dp[k])