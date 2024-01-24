# 준표의 조약돌_BOJ15831

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N, B, W = map(int, sys.stdin.readline().split())
road = list(sys.stdin.readline().strip())
answer = 0

s = 0; e = 0
b = 0; w = 0

while (e < N):
	if (road[e] == 'B'):
		b += 1
	else:
		w += 1
	
	while (b > B):
		if (road[s] == 'B'):
			b -= 1
		else:
			w -= 1
		s += 1

	if (w >= W and b <= B):
		answer = max(answer, e - s + 1)
	e += 1

print(answer)