# 등차수열과 쿼리_BOJ23888

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

a, d = map(int, sys.stdin.readline().split())
q = int(sys.stdin.readline())

for _ in range(q):
	t, l, r = map(int, sys.stdin.readline().split())

	if (t == 1):
		print((r - l + 1) * a + (r - 1) * r // 2 * d - (l - 1) * (l - 2) // 2 * d)

	if (t == 2):
		if (l == r):
			print((r - 1) * d + a)
		else:
			print(gcd(a, d))