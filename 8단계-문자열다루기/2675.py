# 백준 2675번 문제. 문자열 반복
import sys

T = int(sys.stdin.readline())

for i in range(T):
    R, S = map(str, sys.stdin.readline().split())
    P = ''
    for j in S:
        P += int(R)*j
    print(P)

# 64ms
