# 직사각형과 쿼리_BOJ14846

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
lst = [[0] * (N + 1)] + [[0] + list(map(int, sys.stdin.readline().split())) for _ in range(N)]
dp = [[[0] * 11 for _ in range(N + 1)] for _ in range(N + 1)]

for i in range(1, N + 1):
	for j in range(1, N + 1):
		for k in range(1, 11):
			if (k == lst[i][j]):
				dp[i][j][k] += 1
			dp[i][j][k] += dp[i][j-1][k] + dp[i-1][j][k] - dp[i-1][j-1][k]

Q = int(sys.stdin.readline())

for _ in range(Q):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    answer = 0
	
    for k in range(1, 11):
        if dp[x2][y2][k] - dp[x2][y1 - 1][k] - dp[x1 - 1][y2][k] + dp[x1 - 1][y1 - 1][k] > 0:
            answer += 1

    print(answer)