# 캔 주기_BOJ25602

import sys

N, K = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))
rang = [list(map(int, sys.stdin.readline().split())) for _ in range(K)]
mary = [list(map(int, sys.stdin.readline().split())) for _ in range(K)]
answer = 0

def back(s, cnt):
	global answer
	if (cnt == K):
		answer = max(answer, s)
		return
	
	for i in range(N):
		if (A[i] == 0):
			continue
		s += rang[cnt][i]
		A[i] -= 1
		
		for j in range(N):
			if (A[j] == 0):
				continue
			s += mary[cnt][j]
			A[j] -= 1
			back(s, cnt + 1)
			A[j] += 1
			s -= mary[cnt][j]
		
		s -= rang[cnt][i]
		A[i] += 1
		
back(0, 0)
print(answer)