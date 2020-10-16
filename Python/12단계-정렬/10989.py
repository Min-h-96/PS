# 백준 10989번 문제.
import sys

N = int(sys.stdin.readline())
C = [0 for i in range(10000)]

for i in range(N):
    n = int(sys.stdin.readline())
    C[n-1] += 1

for i in range(len(C)):
    for j in range(C[i]):
        print(i+1)

# 9800ms
