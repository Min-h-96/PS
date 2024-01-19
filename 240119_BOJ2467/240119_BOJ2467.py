# 용액_BOJ23888

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
lst = list(map(int, sys.stdin.readline().split()))
total = int(2e9 + 1)
answer = (lst[0], lst[N - 1])

s = 0; e = N - 1
while (s < e):
	cur = abs(lst[s] + lst[e])

	if (cur < total):
		total = cur
		answer = (lst[s], lst[e])

	if (abs(lst[s]) < abs(lst[e])):
		e -= 1
	else:
		s += 1

print(answer[0], answer[1])