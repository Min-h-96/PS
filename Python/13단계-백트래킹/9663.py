# 백준 9663번 문제. N-queen
import sys

def nqueen(index, n, count):
    if index == n:
        count += 1
        return count
    for i in range(n):
        row[index] = False
        column[index] = False
        nqueen(index+1, n, count)

N = int(sys.stdin.readline())

row = [True] * N
column = [True] * N
diagLeft = True
diagRight = True
cnt = 0

print(nqueen(0, N, cnt))
