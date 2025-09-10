import statistics
import sys

sys.stdin.readline()
l = list(map(int, sys.stdin.readline().split()))
m = int(statistics.median(l))
sys.stdout.write(str(sum(abs(i-m) for i in l)) + "\n")
