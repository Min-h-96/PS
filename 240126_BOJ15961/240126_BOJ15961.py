# 회전 초밥_BOJ15961

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N, d, k, c = map(int, sys.stdin.readline().split())
sushi = [int(sys.stdin.readline()) for _ in range(N)]
answer = 0
dic = {c: 1}

for i in range(k - 1):
	sushi.append(sushi[i])

for i in range(len(sushi)):
	if (sushi[i] in dic):
		dic[sushi[i]] += 1
	else:
		dic[sushi[i]] = 1
	
	if (i >= k):
		dic[sushi[i - k]] -= 1
		if (dic[sushi[i - k]] == 0):
			del dic[sushi[i - k]]
	
	answer = max(answer, len(dic))

print(answer)