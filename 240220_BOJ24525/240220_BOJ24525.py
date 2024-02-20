# SKK 문자열_BOJ24525

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

S = sys.stdin.readline().strip()
v = [0 for _ in range(len(S) + 1)]
cnt = v.copy()
answer = -1

for i in range(len(S)):
	n = 0
	if (S[i] == 'S'):
		n = 2
	if (S[i] == 'K'):
		n = -1
	v[i + 1] = v[i] + n
	if (n == 0):
		cnt[i + 1] = cnt[i]
	else:
		cnt[i + 1] = cnt[i] + 1

dic = {}
for i in range(len(S) + 1):
	if (v[i] not in dic):
		dic[v[i]] = i
	else:
		idx = dic[v[i]]
		if (cnt[idx] == cnt[i]):
			continue
		answer = max(answer, i - idx)

print(answer)