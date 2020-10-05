# 백준 1929번 문제. M이상 N이하 소수 출력
import sys


def checkPrimeNum(n):
    if n == 1:
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True


M, N = map(int, sys.stdin.readline().split())

for i in range(M, N+1):
    if checkPrimeNum(i):
        print(i)

# 3944ms

"""
# 에라토스테네스의 체를 사용했을 경우
def eratos(n):
    lst = [False, False] + [True]*(n-1)
    primes = []

    for i in range(2, n+1):
        if lst[i]:
            primes.append(i)
            for j in range(2*i, n+1, i):
                lst[j] = False
    return primes


M, N = map(int, sys.stdin.readline().split())

li = eratos(N)

for i in li:
    if i >= M:
        print(i)

# 416ms
"""
