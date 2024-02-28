# 스도쿠_BOJ2580

import sys

board = [list(map(int, sys.stdin.readline().split())) for _ in range(9)]
spaces = []

for i in range(9):
	for j in range(9):
		if (board[i][j] == 0):
			spaces.append((i, j))

def checkRow(y, a):
	for i in range(9):
		if a == board[y][i]:
			return False
	return True

def checkCol(x, a):
	for i in range(9):
		if a == board[i][x]:
			return False
	return True

def checkRect(y, x, a):
	ny = y // 3 * 3
	nx = x // 3 * 3
	for i in range(3):
		for j in range(3):
			if a == board[ny + i][nx + j]:
				return False
	return True

def recur(idx):
	if (idx == len(spaces)):
		for i in range(9):
			print(*board[i])
		return
	
	for i in range(1, 10):
		x = spaces[idx][1]
		y = spaces[idx][0]

		if checkRow(y, i) and checkCol(x, i) and checkRect(y, x, i):
			board[y][x] = i
			recur(idx + 1)
			board[y][x] = 0

recur(0)