# 정렬_BOJ17074

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
nums = [-10000000000] + nums + [10000000000]
answer = 0
idx = -1
cnt = 0

for i in range(1, N + 1):
	if (nums[i] < nums[i - 1]):
		idx = i
		cnt += 1

if (cnt > 1):
	print(0)
elif (cnt == 1):
	if nums[idx - 2] <= nums[idx]:
		answer += 1
	if nums[idx - 1] <= nums[idx + 1]:
		answer += 1
	print(answer)
else:
	print(N)