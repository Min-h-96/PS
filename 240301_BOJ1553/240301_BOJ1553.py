# 도미노 찾기_BOJ1553

import sys

board = [list(sys.stdin.readline().strip()) for _ in range(8)]
for i in range(len(board)):
	for j in range(len(board[i])):
		board[i][j] = int(board[i][j])
dic = dict()
checked = [[False for _ in range(7)] for _ in range(8)]
pos = [[1, 0], [0, 1]]
answer = 0

def recur(i, j):
	global answer

	if (i == 8 and j == 0):
		answer += 1
		return
	
	if (checked[i][j]):
		if (j == 6):
			recur(i + 1, 0)
		else:
			recur(i, j + 1)
	else:
		for p in pos:
			ip, jp = p
			if (i + ip == 8 or j + jp == 7):
				continue
			
			domino = (min(board[i][j], board[i + ip][j + jp]), max(board[i][j], board[i + ip][j + jp]))

			if (domino not in dic and checked[i + ip][j + jp] == False):
				dic[domino] = 1
				checked[i][j] = True
				checked[i + ip][j + jp] = True
				if (j + jp == 6):
					recur(i + 1, 0)
				else:
					recur(i, j + 1)
				checked[i][j] = False
				checked[i + ip][j + jp] = False
				del dic[domino]

recur(0, 0)
print(answer)