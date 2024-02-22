# N과 M(1)_BOJ15649

import sys

N, M = map(int, sys.stdin.readline().split())

def back(lst):
	if (len(lst) == M):
		print(*lst)
		return
	for i in range(1, N + 1):
		if (i not in lst):
			lst.append(i)
			back(lst)
			lst.pop()

back([])