from collections import Counter

s = input()
fq = Counter(s)
c = [k for k in fq if fq[k]&1]
if len(c) > 1:
    print("NO SOLUTION")
    exit(0)
else:
    h = ""
    for k in fq:
        if c and k == c[0]: continue
        h += k*(fq[k]//2)
    if c: h += c[0]*(fq[c[0]]//2+1)
    print(h+h[::-1][len(c):])