move = []

def toh(n, s, d, a):
    if n==1:
        move.append((s, d))
        return
    toh(n-1, s, a, d)
    move.append((s,d))
    toh(n-1, a, d, s)

toh(int(input()), 1, 3, 2)
print(len(move))
print("\n".join(" ".join(map(str, m)) for m in move))