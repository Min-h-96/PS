# 팩토리얼 나누기_BOJ15996

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N, A = map(int, sys.stdin.readline().split())
answer = 0

if (N == 0):
    N = 1

a = 1
while (A**a <= N):
    answer += a**(1//A)
    a += 1

print(answer)
