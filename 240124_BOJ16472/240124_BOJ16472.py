# 고냥이_BOJ16472

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
S = sys.stdin.readline().strip()
dic = {}
answer = 0

s = 0; e = 0
dic[S[s]] = 1

while (e < len(S)):
	if (len(dic) <= N):
		answer = max(answer, e - s + 1)
		e += 1
		if (e < len(S)):
			if (S[e] in dic):
				dic[S[e]] += 1
			else:
				dic[S[e]] = 1
	else:
		dic[S[s]] -= 1
		if (dic[S[s]] == 0):
			del dic[S[s]]
		s += 1

print(answer)