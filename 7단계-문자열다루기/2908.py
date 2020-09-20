# 백준 2908번 문제
import sys

A, B = sys.stdin.readline().split()

A = A[::-1]
B = B[::-1]

print(max(A, B))

# 68ms
