# 동작 그만. 밑장 빼기냐?_BOJ20159

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
cards = list(map(int, sys.stdin.readline().split()))
answer = 0

last_diff = cards[N - 1] - cards[N - 2]

diff = []
for i in range(0, N, 2):
	diff.append(cards[i] - cards[i + 1])

idx = diff.index(min(diff))

for i in range(0, N, 2):
	if (i == idx * 2):
		answer += cards[i + 1]
	else:
		answer += cards[i]

print(answer)