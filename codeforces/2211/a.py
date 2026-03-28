tc = int(input())
for _ in range(tc):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print(1)
        continue
    print(*([2] * n))