# 팀 빌딩_BOJ22945

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
x = list(map(int, sys.stdin.readline().split()))
answer = 0

s = 0; e = N - 1
while (s < e):
	answer = max(answer, min(x[s], x[e]) * (e - s - 1))

	if (x[s] < x[e]):
		s += 1
	else:
		e -= 1

print(answer)