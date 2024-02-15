# K번째 수_BOJ1300

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N, K = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))
answer = int(1e9)

A.sort()
B.sort()

s = A[0] * B[0]
e = A[N - 1] * B[N - 1]
while (s <= e):
	m = (s + e) // 2

	cnt = 0
	for a in A:
		d = m // a
		
		start = 0
		end = N - 1
		while (start <= end):
			mid = (start + end) // 2
			
			if (B[mid] <= d):
				start = mid + 1
			else:
				end = mid - 1
		
		else:
			cnt += end + 1
	
	if (cnt >= K):
		answer = m
		e = m - 1
	else:
		s = m + 1

print(answer)

