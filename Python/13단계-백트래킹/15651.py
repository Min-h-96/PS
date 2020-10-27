# 백준 15651번 문제. N과 M #3
import sys


def findSolution(index, N, M):
    if index == M:
        for i in range(M):
            print(result[i], end=' ')
        print()
        return
    for i in range(1, N+1):
        result[index] = i
        findSolution(index+1, N, M)

N, M = map(int, sys.stdin.readline().split())
result = [0] * M
findSolution(0, N, M)

# 2932ms 29380KB

"""
import sys
from itertools import product

def testCase():
    input_val = list(map(int, sys.stdin.readline().split()))
    global N, M
    N, M = input_val

def solve(remain):
    res = list(map(' '.join, product(remain, repeat=M)))
    print('\n'.join(res))

if __name__ == "__main__":
    testCase()
    solve(map(str, list(range(1, N+1))))

# 248ms 110260KB
"""