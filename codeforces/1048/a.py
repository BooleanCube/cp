
def solve():
    a, b = map(int, input().split())
    if a == b: print(0)
    elif max(a,b) % min(a,b) == 0: print(1)
    else: print(2)

tc = int(input())

while tc:
    tc -= 1
    solve()
