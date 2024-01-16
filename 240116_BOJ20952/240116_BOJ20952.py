# 게임 개발자 승희_BOJ20952

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

from collections import deque

N, M = map(int, sys.stdin.readline().split())
A = deque(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))
d = 1e9 + 7
count = [0 for _ in range(7)]

for a in A:
    if (count[a % 7] == 0):
        count[a % 7] = 1
    if (0 not in count):
        break

sum = 0
check = 0
for b in B:
    idx = 0
    if ((check + b) % 7 != 0):
        idx = 7 - (check + b) % 7
    
    if (count[idx]):
        if (count.count(1) == 1):
            continue
        count[idx] = 0
    
    check = (check + b) % 7
    sum += b
    sum %= d

answer = []
for a in A:
    if (count[a % 7]):
        answer.append(int((a + sum) % d))

print(len(answer))
print(*answer)