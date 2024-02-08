# 누가 이길까_BOJ28449

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N, M = map(int, sys.stdin.readline().split())
HI = list(map(int, sys.stdin.readline().split()))
ARC = list(map(int, sys.stdin.readline().split()))
answers = [0, 0, 0]

HI.sort()
ARC.sort()

s = set(ARC)
dic_idx = dict()
dic_cnt = dict()

for a in s:
	dic_idx[a] = ARC.index(a)
	dic_cnt[a] = ARC.count(a)

for h in HI:
	left = 0
	right = M - 1

	while (left <= right):
		mid = (left + right) // 2

		if (ARC[mid] == h):
			break

		if (ARC[mid] < h):
			left = mid + 1
		else:
			right = mid - 1
	
	idx = dic_idx[ARC[mid]]
	cnt = dic_cnt[ARC[mid]]
	
	if (h == ARC[mid]):
		answers[0] += idx
		answers[1] += M - (idx + cnt)
		answers[2] += cnt
	elif (h > ARC[mid]):
		answers[0] += idx + 1
		answers[1] += M - (idx + cnt)
	else:
		answers[0] += idx
		answers[1] += M - (idx + cnt) + 1

print(*answers)