# 소가 길을 건너간 이유 5_BOJ14465

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N, K, B = map(int, sys.stdin.readline().split())
lights = [True for _ in range(N)]
answer = N

# 고장난 신호등 체크
for _ in range(B):
	lights[int(sys.stdin.readline()) - 1] = False

# 맨 처음 K 개의 신호등에서 고장난 신호등의 개수
count = lights[:K].count(False)

for i in range(1, N - K + 1):
	if (lights[i - 1] == False):
		count -= 1
	if (lights[i + K - 1] == False):
		count += 1
	answer = min(answer, count)

print(answer)