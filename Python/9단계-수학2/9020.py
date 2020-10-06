# 백준 9020번 문제. 골드바흐의 추측
# 시간 초과
import sys


def eratos(n):
    lst = [False, False] + [True]*(n-1)
    primes = []

    for i in range(2, n+1):
        if lst[i]:
            primes.append(i)
            for j in range(2*i, n+1, i):
                lst[j] = False
    return primes


def findXY(n):
    prime = eratos(n)
    lst_XY = []
    for x in prime:
        for y in prime:
            if x + y == n:
                lst_XY.append([x, y])

    if len(lst_XY) % 2 == 0:
        del lst_XY[int(len(lst_XY)/2):]
    else:
        del lst_XY[int(len(lst_XY)/2)+1:]

    return lst_XY


T = int(sys.stdin.readline())

for t in range(T):
    n = int(sys.stdin.readline())
    li = findXY(n)
    print(li[len(li)-1][0], li[len(li)-1][1])
