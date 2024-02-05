# 작은 벌점_BOJ16498

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

A, B, C = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))
c = list(map(int, sys.stdin.readline().split()))

a.sort()
b.sort()
c.sort()

def binarySearch(t, arr):
	start = 0
	end = len(arr) - 1
	result = arr[end // 2]
	
	while (start <= end):
		mid = (start + end) // 2
		
		if (arr[mid] == t):
			return t
		
		if (abs(t - arr[mid]) < abs(t - result)):
			result = arr[mid]
		
		if (arr[mid] > t):
			end = mid - 1
		else:
			start = mid + 1
	
	return result

answer = int(1e9)

for p1 in a:
	p2 = binarySearch(p1, b)
	p3_1 = binarySearch(p1, c)
	p3_2 = binarySearch(p2, c)

	r1 = abs(max(p1, p2, p3_1) - min(p1, p2, p3_1))
	r2 = abs(max(p1, p2, p3_2) - min(p1, p2, p3_2))

	r = min(r1, r2)
	answer = min(answer, r)

print(answer)