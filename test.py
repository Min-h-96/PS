import sys


def change_BW(x, y):
    if x == 'B':
        return 'W'
    else:
        return 'B'


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

# for x in range(N-7):
#     for y in range(M-7):
new_chess = [chess_board[0][0]]
count = 0

# for a in range(7):
for b in range(7):
    print(new_chess)
    if new_chess[b] == chess_board[0][b+1]:
        new_chess.append(change_BW(new_chess[b], chess_board[0][b+1]))
        count += 1
    else:
        new_chess.append(chess_board[0][b+1])
print(new_chess)
print(count)
