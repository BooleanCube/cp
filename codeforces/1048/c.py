from collections import deque

def solve():
    k, x = map(int, input().split())
    s = 2 ** k
    tot = 2 * s
    target = (x, tot - x)

    if (s, s) == target:
        print(0)
        print()
        return

    qf = deque([(s, s, 0, 1)])
    qb = deque([target + (0, 1)])
    visf = {(s, s): (0, 1)}
    visb = {target: (0, 1)}

    while qf or qb:
        if qf:
            c, v, cur, ops = qf.popleft()
            if c % 2 == 0:
                nc = c // 2
                nv = v + c // 2
                if (nc, nv) in visb:
                    b_cur, b_ops = visb[(nc, nv)]
                    print(cur + 1 + b_cur)
                    f_aops, f_tops = [], ops << 1
                    while f_tops > 1:
                        f_aops.append((f_tops & 1) + 1)
                        f_tops >>= 1
                    b_aops, b_tops = [], b_ops
                    while b_tops > 1:
                        b_aops.append((b_tops & 1) + 1)
                        b_tops >>= 1
                    print(*(f_aops[::-1] + b_aops))
                    return
                if (nc, nv) not in visf:
                    visf[(nc, nv)] = (cur + 1, ops << 1)
                    qf.append((nc, nv, cur + 1, ops << 1))

            if v % 2 == 0:
                nc = c + v // 2
                nv = v // 2
                if (nc, nv) in visb:
                    b_cur, b_ops = visb[(nc, nv)]
                    print(cur + 1 + b_cur)
                    f_aops, f_tops = [], (ops << 1) + 1
                    while f_tops > 1:
                        f_aops.append((f_tops & 1) + 1)
                        f_tops >>= 1
                    b_aops, b_tops = [], b_ops
                    while b_tops > 1:
                        b_aops.append((b_tops & 1) + 1)
                        b_tops >>= 1
                    print(*(f_aops[::-1] + b_aops))
                    return
                if (nc, nv) not in visf:
                    visf[(nc, nv)] = (cur + 1, (ops << 1) + 1)
                    qf.append((nc, nv, cur + 1, (ops << 1) + 1))

        if qb:
            c, v, cur, ops = qb.popleft()
            if c * 2 <= tot:
                pc = c * 2
                pv = v - c
                if pv >= 0:
                    if (pc, pv) in visf:
                        f_cur, f_ops = visf[(pc, pv)]
                        print(f_cur + cur + 1)
                        f_aops, f_tops = [], f_ops << 1
                        while f_tops > 1:
                            f_aops.append((f_tops & 1) + 1)
                            f_tops >>= 1
                        b_aops, b_tops = [], ops
                        while b_tops > 1:
                            b_aops.append((b_tops & 1) + 1)
                            b_tops >>= 1
                        print(*(f_aops[::-1] + b_aops))
                        return
                    if (pc, pv) not in visb:
                        visb[(pc, pv)] = (cur + 1, (ops << 1))
                        qb.append((pc, pv, cur + 1, ops << 1))

            if v * 2 <= tot:
                pv = v * 2
                pc = c - v
                if pc >= 0:
                    if (pc, pv) in visf:
                        f_cur, f_ops = visf[(pc, pv)]
                        print(f_cur + cur + 1)
                        f_aops, f_tops = [], (f_ops << 1) + 1
                        while f_tops > 1:
                            f_aops.append((f_tops & 1) + 1)
                            f_tops >>= 1
                        b_aops, b_tops = [], ops
                        while b_tops > 1:
                            b_aops.append((b_tops & 1) + 1)
                            b_tops >>= 1
                        print(*(f_aops[::-1] + b_aops))
                        return
                    if (pc, pv) not in visb:
                        visb[(pc, pv)] = (cur + 1, (ops << 1) + 1)
                        qb.append((pc, pv, cur + 1, (ops << 1) + 1))

tc = int(input())
while tc:
    tc -= 1
    solve()
