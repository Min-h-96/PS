# 매직 스퀘어로 변경하기_BOJ16945

import sys

table = []
for _ in range(3):
	table += list(map(int, sys.stdin.readline().split()))
visited = [False for _ in range(9)]
lst = [0 for _ in range(9)]
answer = 45

def isValid(lst):
	if (sum(lst[:3]) == 15 and sum(lst[3:6]) == 15 and sum(lst[6:9]) == 15 and
		lst[0] + lst[3] + lst[6] == 15 and lst[1] + lst[4] + lst[7] == 15 and
		lst[2] + lst[5] + lst[8] == 15 and lst[0] + lst[4] + lst[8] == 15 and
		lst[2] + lst[4] + lst[6] == 15):
		return True
	else:
		return False

def perm(cur):
	global answer

	if cur == 9 and isValid(lst):
		diff = 0
		for i in range(9):
			diff += abs(table[i] - lst[i])
		answer = min(answer, diff)
		return
	
	for i in range(9):
		if (visited[i]):
			continue

		visited[i] = True
		lst[cur] = i + 1
		perm(cur + 1)
		visited[i] = False

perm(0)
print(answer)