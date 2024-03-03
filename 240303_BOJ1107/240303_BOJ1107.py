# 리모컨_BOJ1107

import sys

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
broken = list(map(int, sys.stdin.readline().split())) if M > 0 else []
dic = dict()
for b in broken:
	dic[b] = 1
answer = abs(100 - N)

for n in range(1000001):
	n = str(n)

	for i in range(len(n)):
		if int(n[i]) in dic:
			break
	else:
		answer = min(answer, abs(int(n) - N) + len(n))

print(answer)