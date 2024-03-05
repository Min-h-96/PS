# 단지번호붙이기_BOJ2667

import sys
from collections import deque

N = int(sys.stdin.readline())
board = [list(map(int, sys.stdin.readline().strip())) for _ in range(N)]
answers = []

dq = deque()
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

for i in range(N):
	for j in range(N):
		if (board[i][j] == 0):
			continue
		
		dq.append((i, j))
		board[i][j] = 0
		cnt = 1
		while (len(dq)):
			cy, cx = dq.popleft()

			for k in range(4):
				ny = cy + dy[k]
				nx = cx + dx[k]

				if (ny < 0 or ny >= N or nx < 0 or nx >= N or board[ny][nx] == 0):
					continue
				
				dq.append((ny, nx))
				board[ny][nx] = 0
				cnt += 1
		
		answers.append(cnt)

answers.sort()
print(len(answers))
for answer in answers:
	print(answer)