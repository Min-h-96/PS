# 개똥벌레_BOJ3020

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N, H = map(int, sys.stdin.readline().split())
floor = [0] * H
ceiling = [0] * H

for i in range(N):
	h = int(sys.stdin.readline())

	if (i % 2 == 0):
		floor[h - 1] += 1
	else:
		ceiling[H - h] += 1

s = 0
for i in range(H - 1, -1, -1):
	s += floor[i]
	floor[i] = s

s = 0
for i in range(H):
	s += ceiling[i]
	ceiling[i] = s

answers = [0] * H
for i in range(H):
	answers[i] = floor[i] + ceiling[i]

m = min(answers)
print(m, answers.count(m))