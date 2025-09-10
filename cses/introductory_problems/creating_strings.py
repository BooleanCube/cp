from itertools import permutations
p = sorted(set(permutations(list(input()))))
print(len(p))
for w in p: print("".join(w))