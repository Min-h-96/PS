# 마라탕 재료 고르기_BOJ28447

import sys
from itertools import combinations

N, K = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
answer = int(-1e9)

comb = list(combinations([i for i in range(N)], K))

for c in comb:
	taste = 0
	for i in range(len(c) - 1):
		for j in range(i + 1, len(c)):
			taste += board[c[i]][c[j]]
	answer = max(answer, taste)

if (K == 1):
	print(0)
else:
	print(answer)