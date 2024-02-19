# 나무꾼 이다솜_BOJ1421

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N, C, W = map(int, sys.stdin.readline().split())
trees = [int(sys.stdin.readline()) for _ in range(N)]
answer = 0

for i in range(1, max(trees) + 1):
	money = 0
	for t in trees:
		K = t // i
		if (t % i == 0):
			cnt = t // i - 1
		else:
			cnt = t // i
		
		if (K * i * W - cnt * C < 0):
			continue
		money += K * i * W - cnt * C
	
	answer = max(answer, money)

print(answer)