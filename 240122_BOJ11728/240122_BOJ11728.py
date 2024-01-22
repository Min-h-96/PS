# 배열 합치기_BOJ11728

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N, M = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))
answer = []

a = 0; b = 0
while (a < len(A) and b < len(B)):
	if (A[a] <= B[b]):
		answer.append(A[a])
		a += 1
	else:
		answer.append(B[b])
		b += 1

if (a == len(A)):
	answer += B[b:]
if (b == len(B)):
	answer += A[a:]

print(*answer)