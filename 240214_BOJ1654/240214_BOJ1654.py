# 랜선 자르기_BOJ1654

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

K, N = map(int, sys.stdin.readline().split())
lines = [int(sys.stdin.readline()) for _ in range(K)]
answer = 0

s = 1
e = max(lines)
while (s <= e):
	mid = (s + e) // 2

	cnt = 0
	for l in lines:
		cnt += l // mid
	
	if (cnt >= N):
		s = mid + 1
		answer = max(answer, mid)
	else:
		e = mid - 1

print(answer)