# 숫자 카드_BOJ10815

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
cards = set(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
answers = []

for n in nums:
	if (n in cards):
		answers.append(1)
	else:
		answers.append(0)

print(*answers)