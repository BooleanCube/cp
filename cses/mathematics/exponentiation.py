import sys
n=int(sys.stdin.readline())
for i in range(n):
    l=list(map(int,sys.stdin.readline().split()))
    print(pow(l[0],l[1],1000000007))