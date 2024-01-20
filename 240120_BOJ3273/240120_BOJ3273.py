# 두 수의 합_BOJ3273

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
x = int(sys.stdin.readline())
answer = 0

a.sort()

s = 0; e = n - 1
while (s < e):
	cur = a[s] + a[e]
	if (cur == x):
		answer += 1

	if (cur > x):
		e -= 1
	else:
		s += 1

print(answer)