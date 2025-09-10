import math

def countSetBits(n):
    if n == 0: return 0
    m = int(math.log2(n))
    if n == (1 << (m+1)) - 1: return (m + 1) * (1 << m)
    n -= 1 << m
    return (n + 1) + countSetBits(n) + (m * (1 << (m - 1)))

n = int(input())
print(countSetBits(n))
