# 나는 정말 휘파람을 못 불어_BOJ24956

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
S = sys.stdin.readline().strip()
mod = 1000000007
answer = 0

w = 0
h = 0
e = 0

for s in S:
	if (s == 'W'):
		w += 1
	elif (s == 'H'):
		h += w
	elif (s == 'E'):
		answer *= 2
		answer += e
		answer %= mod
		e += h

print(answer)