# 백준 4948번 문제. 베르트랑 공준
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


while True:
    n = int(sys.stdin.readline())
    count = 0
    if n == 0:
        exit(0)
    li = eratos(2*n)
    print(len([i for i in li if i > n]))


# 2468ms
