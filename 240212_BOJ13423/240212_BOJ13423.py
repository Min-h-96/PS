# Three Dots_BOJ13423

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

T = int(sys.stdin.readline())

for _ in range(T):
	N = int(sys.stdin.readline())
	X = list(map(int, sys.stdin.readline().split()))
	X.sort()
	answer = 0

	dic = {}
	for x in X:
		dic[x] = 0

	for i in range(N - 1):
		for j in range(i + 1, N):
			if ((X[i] + X[j]) % 2 != 0):
				continue

			if ((X[i] + X[j]) // 2 in dic):
				answer += 1
	
	print(answer)