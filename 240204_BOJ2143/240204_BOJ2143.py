# 두 배열의 합_BOJ2143

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

T = int(sys.stdin.readline())
n = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
B = list(map(int, sys.stdin.readline().split()))

sumA = []
for i in range(len(A)):
	s = A[i]
	sumA.append(s)
	for j in range(i + 1, len(A)):
		s += A[j]
		sumA.append(s)

sumB = dict()
for i in range(len(B)):
	s = B[i]
	if (s not in sumB):
		sumB[s] = 1
	else:
		sumB[s] += 1
	for j in range(i + 1, len(B)):
		s += B[j]
		if (s not in sumB):
			sumB[s] = 1
		else:
			sumB[s] += 1

answer = 0
for a in sumA:
	t = T - a
	if (t in sumB):
		answer += sumB[t]

print(answer)