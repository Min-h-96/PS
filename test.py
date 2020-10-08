import sys

N, M = map(int, sys.stdin.readline().split())

board = []

for n in range(N):
    board.append(input())
print(board)
