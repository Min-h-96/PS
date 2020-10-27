# 백준 15649번 문제. N과 M #1
import sys


def findSolution(index, N, M):
    if index == M:
        for i in range(M):
            print(result[i], end=' ')
        print()
        return
    for i in range(1, N+1):
        if check[i] is True:
            continue
        result[index] = i
        check[i] = True
        findSolution(index+1, N, M)
        check[i] = False

N, M = map(int, sys.stdin.readline().split())
check = [False] * (N+1)
result = [0] * M
findSolution(0, N, M)

# 276ms 29380KB

"""
import sys
from itertools import permutations

input_val = list(map(int, sys.stdin.readline().split()))
N, M = input_val

def solve(remain):
    res = list(map(' '.join, permutations(remain, M)))
    print('\n'.join(res))

solve(map(str, list(range(1, N+1))))

# 72ms 32512KB
"""