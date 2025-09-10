from collections import defaultdict

n, t = map(int, input().split())
l = list(map(int, input().split()))
s = defaultdict(list)
for i in range(n):
    for j in range(i+1, n):
        s[t-(l[i]+l[j])].append((i,j))
for i in range(n):
    for j in range(i+1, n):
        for k in s[l[i]+l[j]]:
            if len(set([i,j,k[0],k[1]])) == 4:
                   print(*sorted([i+1,j+1,k[0]+1,k[1]+1]))
                   exit(0)
print("IMPOSSIBLE")
        
