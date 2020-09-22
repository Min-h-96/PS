# 백준 2839번 문제. 설탕 배달
import sys


def sugar(N):
    for y in range((N//3)+1):
        for x in range((N//5)+1):
            if ((5*x + 3*y) == N):
                return x+y

    return -1


N = int(sys.stdin.readline())

print(sugar(N))
