# 공유기 설치_BOJ2110

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N, C = map(int, sys.stdin.readline().split())
X = [int(sys.stdin.readline()) for _ in range(N)]
X.sort()
answer = int(1e9)

s = 1
e = X[N - 1] - X[0]
while (s <= e):
	mid = (s + e) // 2
	cur = X[0]

	cnt = 1
	for i in range(1, N):
		if (X[i] >= cur + mid):
			cnt += 1
			cur = X[i]
	
	if (cnt < C):
		e = mid - 1
	else:
		answer = mid
		s = mid + 1

print(answer)