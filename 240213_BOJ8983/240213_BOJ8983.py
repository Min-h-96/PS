# 사냥꾼_BOJ8983

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

M, N, L = map(int, sys.stdin.readline().split())
pos = list(map(int, sys.stdin.readline().split()))
animals = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]
answer = 0

pos.sort()

for animal in animals:
	s = 0
	e = len(pos) - 1

	if (animal[1] > L):
		continue

	while (s <= e):
		mid = (s + e) // 2
		d = abs(animal[0] - pos[mid]) + animal[1]

		if (d <= L):
			answer += 1
			break

		if (animal[0] >= pos[mid]):
			s = mid + 1
		else:
			e = mid - 1

print(answer)