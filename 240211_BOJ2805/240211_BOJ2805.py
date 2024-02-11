# 나무 자르기_BOJ2805

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N, M = map(int, sys.stdin.readline().split())
trees = list(map(int, sys.stdin.readline().split()))
answer = 0

s = 0
e = max(trees)

while (s <= e):
	mid = (s + e) // 2

	total = 0
	for t in trees:
		if (t > mid):
			total += t - mid

	if (total >= M):
		answer = max(answer, mid)
		s = mid + 1
	else:
		e = mid - 1

print(answer)