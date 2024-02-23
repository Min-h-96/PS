# 캠프 준비_BOJ16938

import sys

N, L, R, X = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))
A.sort()
visited = [False for _ in range(N)]

global answer
answer = 0

def back(start, cur, s):
	global answer
	if (s > R):
		return

	if (L <= s and s <= R and A[cur] - A[start] >= X):
		answer += 1

	for i in range(cur + 1, N):
		if (visited[i]):
			continue
		visited[i] = True
		back(start, i, s + A[i])
		visited[i] = False

for i in range(N):
	visited[i] = True
	back(i, i, A[i])
	visited[i] = False

print(answer)