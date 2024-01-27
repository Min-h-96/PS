# 같이 눈사람 만들래?_BOJ20366

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
H = list(map(int, sys.stdin.readline().split()))
H.sort()
answer = int(2e9)

for i in range(N - 3):
	for j in range(i + 3, N):
		one = H[i] + H[j]
		s = i + 1
		e = j - 1

		while (s < e):
			two = H[s] + H[e]
			answer = min(answer, abs(one - two))

			if (one > two):
				s += 1
			else:
				e -= 1

print(answer)