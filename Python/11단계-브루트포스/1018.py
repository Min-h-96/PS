# 백준 1018번 문제
import sys


def change_BW(x):
    if x == 'B':
        return 'W'
    else:
        return 'B'


N, M = map(int, sys.stdin.readline().split())

chess_board = []

for n in range(N):
    chess_board.append(input())

count_lst = []
for x in range(N-7):
    for y in range(M-7):
        new_chess = ['B']
        count = 0
        if new_chess[0] != chess_board[x][y]:
            count += 1
        for a in range(8):
            if a == 0:
                for b in range(7):
                    if new_chess[b] == chess_board[x][y+b+1]:
                        new_chess.append(change_BW(new_chess[b]))
                        count += 1
                    else:
                        new_chess.append(chess_board[x][y+b+1])
            else:
                if new_chess[8*(a-1)] == chess_board[a+x][y]:
                    new_chess.append(change_BW(new_chess[8*(a-1)]))
                    count += 1
                else:
                    new_chess.append(chess_board[a+x][y])
                for b in range(7):
                    if new_chess[8*a+b] == chess_board[a+x][y+b+1]:
                        new_chess.append(change_BW(new_chess[8*a+b]))
                        count += 1
                    else:
                        new_chess.append(chess_board[a+x][y+b+1])
        count_lst.append(count)
        new_chess = ['W']
        count = 0
        if new_chess[0] != chess_board[x][y]:
            count += 1
        for a in range(8):
            if a == 0:
                for b in range(7):
                    if new_chess[b] == chess_board[x][y+b+1]:
                        new_chess.append(change_BW(new_chess[b]))
                        count += 1
                    else:
                        new_chess.append(chess_board[x][y+b+1])
            else:
                if new_chess[8*(a-1)] == chess_board[a+x][y]:
                    new_chess.append(change_BW(new_chess[8*(a-1)]))
                    count += 1
                else:
                    new_chess.append(chess_board[a+x][y])
                for b in range(7):
                    if new_chess[8*a+b] == chess_board[a+x][y+b+1]:
                        new_chess.append(change_BW(new_chess[8*a+b]))
                        count += 1
                    else:
                        new_chess.append(chess_board[a+x][y+b+1])
        count_lst.append(count)
print(min(count_lst))

# 200ms
