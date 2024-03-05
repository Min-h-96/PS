# 단지번호붙이기_BOJ2667

import sys
from collections import deque

N = int(sys.stdin.readline())
board = [list(sys.stdin.readline().strip()) for _ in range(N)]
answers = []
checked = [[False for _ in range(N)] for _ in range(N)]
for i in range(N):
	for j in range(N):
		if (board[i][j] == '0'):
			checked[i][j] = True

dq = deque()
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

for i in range(N):
	for j in range(N):
		if (checked[i][j]):
			continue
			
		dq.append((i, j))
		checked[i][j] = True
		cnt = 1
		while (len(dq)):
			cy, cx = dq.popleft()

			for i in range(4):
				ny = cy + dy[i]
				nx = cx + dx[i]

				if (ny < 0 or ny >= N or nx < 0 or nx >= N or checked[ny][nx]):
					continue
				
				dq.append((ny, nx))
				checked[ny][nx] = True
				cnt += 1

		answers.append(cnt)

answers.sort()
print(len(answers))
for answer in answers:
	print(answer)