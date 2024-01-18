# 실질적 약수_BOJ2247

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
answer = 0

for n in range(2, N // 2 + 1):
	answer += (N // n - 1) * n

print(answer % 1000000)