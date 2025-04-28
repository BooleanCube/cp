for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    if sum(a) == 0:
        print("NO")
        continue
    sm, flag = 0, 0
    for i in range(n):
        sm += a[i]
        if sm == 0:
            flag = 1
            break
    if flag: a = a[::-1]
    print("YES")
    print(*a)
