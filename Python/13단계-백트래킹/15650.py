# 백준 15650번 문제. N과 M #2
import sys


def findSolution(num, index, N, M):
    if index == M:
        for i in range(M):
            print(result[i], end=' ')
        print()
        return
    for i in range(num+1, N+1):
        result[index] = i
        findSolution(i, index+1, N, M)

N, M = map(int, sys.stdin.readline().split())
result = [0] * M
findSolution(0, 0, N, M)

# 64ms 29380KB

"""
import sys
from itertools import combinations

input_val = list(map(int, sys.stdin.readline().split()))
N, M = input_val

def solve(remain):
    res = list(map(' '.join, combinations(remain, M)))
    print('\n'.join(res))

solve(map(str, list(range(1, N+1))))

# 60ms 29380KB
"""