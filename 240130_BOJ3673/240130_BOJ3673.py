# 나눌 수 있는 부분 수열_BOJ3673

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

c = int(sys.stdin.readline())

for _ in range(c):
	d, n = map(int, sys.stdin.readline().split())
	nums = list(map(int, sys.stdin.readline().split()))
	sums = [0]

	sum = 0
	for num in nums:
		sum += num
		sums.append(sum)
	
	print(sums)