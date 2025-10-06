"""
from collections import Counter

n = int(input())

ans = []
for mask in range(1 << n):
    b = []
    for i in range(n):
        cur = 1 + sum(1 for j in range(i+1, n) if (mask & (1 << j) == 0)) + sum(1 for j in range(i) if (mask & (1 << j) > 0))
        b.append(cur)
    # print(bin(mask)[2:])
    # print(*b)
    ans.append(tuple(b))

print(Counter(ans).most_common())


"""


from collections import Counter

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    if n == 2:
        print(1)
        return

    if len(set(a)) == 1 and a[0] == n//2+1 and n % 2 == 1:
        print(2)
    else:
        tps = sum(1 for i in range(n - 1) if abs(a[i] - a[i+1]) > 1)
        if tps:
            print(0)
            return

        c = [0] * n
        for i in range(n - 1):
            diff = a[i+1] - a[i]
            if diff == 1:
                if c[i+1] == 'R' or c[i] == 'R':
                    print(0)
                    return
                c[i+1] = 'L'
                c[i] = 'L'
            elif diff == -1:
                if c[i] == 'L' or c[i+1] == 'L':
                    print(0)
                    return
                c[i] = 'R'
                c[i+1] = 'R'
            else:
                if c[i] == 'R' or c[i+1] == 'L':
                    print(0)
                    return
                c[i] = 'L'
                c[i+1] = 'R'

        for i in range(n):
            if not c[i]: c[i] = 'R'
        # print('y', c)
        lsuff = [int(c[i] == 'R') for i in range(n)]
        rpref = [int(c[i] == 'L') for i in range(n)]
        for i in range(n-2, -1, -1): lsuff[i] += lsuff[i+1]
        for i in range(1, n): rpref[i] += rpref[i-1]
        # print(a)
        # print(rpref)
        # print(lsuff)
        d = [1 + lsuff[1]]
        if 1 + lsuff[1] != a[0]:
            print(0)
            return
        if 1 + rpref[-2] != a[-1]:
        print(0)
        return
         for i in range(1, n-1):
        d.append(1 + rpref[i-1] + lsuff[i+1])
        if 1 + rpref[i-1] + lsuff[i+1] != a[i]:
            print(0)
                return
        d.append(1 + rpref[-2])
        # print(d)
        print(1)

for _ in range(int(input())): solve()
