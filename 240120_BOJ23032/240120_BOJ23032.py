# 서프라이즈~_BOJ23032

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
W = list(map(int, sys.stdin.readline().split()))
answer = 0
E = int(2e8)

for i in range(N - 1):
	s = i
	m = i + 1
	e = i + 1

	left = sum(W[s:m])
	right = sum(W[m:e])

	while (e < N):
		if (left <= right):
			left += W[m]
			right -= W[m]
			m += 1
		else:
			right += W[e]
			e += 1
		
		if (e == m):
			right += W[e]
			e += 1
		
		if (max(left, right) - min(left, right) <= E):
			if (max(left, right) - min(left, right) == E):
				answer = max(answer, left + right)
			else:
				answer = left + right
			E = max(left, right) - min(left, right)		

print(answer)