# 정수 삼각형
import sys

n = int(sys.stdin.readline())
vals = []

for i in range(n):
	val = list(map(int, sys.stdin.readline().split()))
	vals.append(val)

for i in range(1, n):
	for j in range(i + 1):
		if (j == 0):
			vals[i][j] += vals[i - 1][j]
		elif (j == i):
			vals[i][j] += vals[i - 1][j - 1]
		else:
			vals[i][j] += max(vals[i - 1][j - 1], vals[i - 1][j])

print(max(vals[n - 1]))