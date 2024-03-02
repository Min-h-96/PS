# 영재의 시험_BOJ19949

import sys

answers = list(map(int, sys.stdin.readline().split()))
answer = 0

def dfs(depth, score, selected):
	global answer

	if (score + 10 - depth < 5):
		return
	
	if depth == 10:
		if (score >= 5):
			answer += 1
		return
	
	for i in range(1, 6):
		if (depth >= 2 and i == selected[depth - 1] and i == selected[depth - 2]):
			continue
		if (i == answers[depth]):
			selected.append(i)
			dfs(depth + 1, score + 1, selected)
			selected.pop()
		else:
			selected.append(i)
			dfs(depth + 1, score, selected)
			selected.pop()

dfs(0, 0, [])
print(answer)