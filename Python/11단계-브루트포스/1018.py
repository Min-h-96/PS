# 백준 1018번 문제
import sys

# N, M = map(int, sys.stdin.readline().split())

# chess_board = sys.stdin.read().split()

chess_board = [
    'BBBBBBBBWBWBW',
    'BBBBBBBBBWBWB',
    'BBBBBBBBWBWBW',
    'BBBBBBBBBWBWB',
    'BBBBBBBBWBWBW',
    'BBBBBBBBBWBWB',
    'BBBBBBBBWBWBW',
    'BBBBBBBBBWBWB',
    'WWWWWWWWWWBWB',
    'WWWWWWWWWWBWB'
]

N = 10
M = 13

total = []

for z in range(M-7):
    wrong_lst = []
    for x in range(8):
        wrong = 0
        for y in range(7):
            if chess_board[x][y+z] != chess_board[x][y+z+1]:
                continue
            else:
                wrong += 1
        wrong_lst.append(wrong)
    total.append(sum(wrong_lst))
print(wrong_lst)
print(total)
