# 수열_BOJ2559

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N, K = map(int, sys.stdin.readline().split())
T = list(map(int, sys.stdin.readline().split()))
answer = -100 * K

sum = 0
for i in range(N):
	sum += T[i]

	if (i > K - 1):
		sum -= T[i - K]
	
	if (i >= K - 1):
		answer = max(answer, sum)

print(answer)