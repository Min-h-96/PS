# 편의점 2_BOJ14400

import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

n = int(sys.stdin.readline())
X = []; Y = []

for _ in range(n):
    x, y = map(int, sys.stdin.readline().split())
    X.append(x)
    Y.append(y)

X.sort()
Y.sort()

a = X[n//2]; b = Y[n//2]

answer = 0
for i in range(n):
    answer += abs(a - X[i]) + abs(b - Y[i])

print(answer)