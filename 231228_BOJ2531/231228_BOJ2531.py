# 회전 초밥_BOJ2531

import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

N, d, k, c = map(int, sys.stdin.readline().split())
sushi = []
answer = 0

for _ in range(N):
    sushi.append(int(sys.stdin.readline()))
for i in range(k - 1):
    sushi.append(sushi[i])

for i in range(N):
    eat = sushi[i : i + k]
    eat.append(c)
    answer = answer if answer >= len(set(eat)) else len(set(eat))

print(answer)