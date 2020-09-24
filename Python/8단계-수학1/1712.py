# 백준 1712번 문제. 손익분기점
import sys

A, B, C = map(int, sys.stdin.readline().split())

if B >= C:
    print(-1)
else:
    print(A//(C-B)+1)

# 64ms
