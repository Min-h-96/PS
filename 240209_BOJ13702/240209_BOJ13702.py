# 이상한 술집_BOJ13702

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N, K = map(int, sys.stdin.readline().split())
drinks = []
total = 0

for _ in range(N):
	drink = int(sys.stdin.readline())
	drinks.append(drink)
	total += drink

s = max(drinks) // K
e = total // K
answer = 0
while (s <= e):
	mid = (s + e) // 2

	cnt = 0
	for d in drinks:
		cnt += d // mid
	
	if (cnt >= K):
		answer = max(answer, mid)
	
	if (cnt >= K):
		s = mid + 1
	else:
		e = mid - 1

print(answer)

# 막걸리를 균등하게 분배했을 때, 꼭 K 잔이 나올 때가 최대값이 아닐 수 있다.