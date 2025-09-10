dp = [0]+[2**i for i in range(6)]
n = int(input())
for i in range(7,n+1):dp.append(sum(dp[i-6:])%(1000000007))
print(dp[n])