n = int(input())
l = list(map(int, input().split()))
edges = {}
for i in range(n-1):
    if l[i]-1 not in edges: edges[l[i]-1] = [i+1]
    else: edges[l[i]-1].append(i+1)


levels = {}

def dfs(no, de):
    stack = [(no, de)]
    while len(stack) > 0:
        current = stack.pop(-1)
        node = current[0]
        depth = current[1]
        if depth not in levels: levels[depth] = [node]
        else: levels[depth].append(node)
        if node not in edges: continue
        for next in edges[node]:
            stack.append((next, depth+1))
    if node not in edges: return
    for next in edges[node]:
        dfs(next, depth+1)

dfs(0, 0)

size = [0]*(n)
for d in sorted(levels.keys(), reverse=1):
    if d==0:break
    for node in levels[d]:
        size[l[node-1]-1] += size[node]+1

print(" ".join(map(str, size)))
