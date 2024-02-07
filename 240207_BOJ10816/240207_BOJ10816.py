# 숫자 카드 2_BOJ10816

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
cards = list(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline())
lst = list(map(int, sys.stdin.readline().split()))
dic = dict()

for l in lst:
	dic[l] = 0

for c in cards:
	if (c in dic):
		dic[c] += 1

for i in range(M):
	if (i == M - 1):
		print(dic[lst[i]], end="")
	else:
		print(dic[lst[i]], end=" ")
print()