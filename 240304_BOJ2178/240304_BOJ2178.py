# 미로 탐색_BOJ2178

import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())
board = [list(sys.stdin.readline().strip()) for _ in range(N)]
answer = N*M
checked = [[False for _ in range(M)] for _ in range(N)]
for i in range(N):
	for j in range(M):
		if (board[i][j] == '0'):
			checked[i][j] = True

dq = deque()
dq.append((0, 0, 1))
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

while (len(dq)):
	cy, cx, cnt = dq.popleft()

	if (cy == N - 1 and cx == M - 1):
		answer = min(answer, cnt)
		continue

	for i in range(4):
		ny = cy + dy[i]
		nx = cx + dx[i]

		if (ny < 0 or ny >= N or nx < 0 or nx >= M or checked[ny][nx]):
			continue

		dq.append((ny, nx, cnt + 1))
		checked[ny][nx] = True

print(answer)