# 부분수열의 합_BOJ1182

import sys

N, S = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))
visited = [False for _ in range(N)]
global answer
answer = 0

def back(s, cnt, start):
	global answer
	if (cnt > 0 and s == S):
		answer += 1

	for i in range(start, N):
		if (visited[i]):
			continue
		visited[i] = True
		back(s + nums[i], cnt + 1, i + 1)
		visited[i] = False

back(0, 0, 0)
print(answer)