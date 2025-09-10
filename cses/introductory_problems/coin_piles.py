for _ in range(int(input())):
    a, b = map(int, input().split())
    a, b = min(a,b), max(a,b)
    print(["NO", "YES"][(a+b)%3 == 0 and a*2 >= b])