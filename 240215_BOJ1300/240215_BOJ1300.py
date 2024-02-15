# K번째 수_BOJ1300

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
k = int(sys.stdin.readline())

s = 1
e = N*N
answer = int(1e9)

while (s <= e):
	mid = (s + e) // 2

	cnt = 0
	for n in range(1, N + 1):
		c = mid // n

		if (c >= N):
			cnt += N
		else:
			cnt += c
	
	if (cnt >= k):
		answer = min(answer, mid)
		e = mid - 1
	else:
		s = mid + 1

print(answer)