r, c = map(int, input().split())
s = [list(input()) for _ in range(r)]
a = "ABCD"
ans = s.copy()
for i in range(r):
    for j in range(c):
        st = set([ans[i][j]])
        if i: st.add(ans[i-1][j])
        if j: st.add(ans[i][j-1])
        for k in range(4):
            if a[k] in st: continue
            ans[i][j] = a[k]
            break
for row in ans: print("".join(row))