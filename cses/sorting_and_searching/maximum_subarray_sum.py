n = int(input()); l, ps, mn, pre = list(map(int,input().split())), [0]*(n+1), 0, 0; l = [l[0]]+[(pre:=pre+l[i-2])+l[i-1] for i in range(2, n+1)]
print(max(a-mn+(mn:=min(mn, a))-mn for a in l))