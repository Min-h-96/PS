# 백준 1929번 문제. M이상 N이하 소수 출력
import sys


def checkPrimeNum(n):
    check = True
    if n == 1:
        check = False
    else:
        for i in range(2, int(n**0.5)+1):
            if n % i == 0:
                check = False
                break
            else:
                continue
    if check == True:
        return n


M, N = map(int, sys.stdin.readline().split())

for i in range(M, N+1):
    if checkPrimeNum(i) != None:
        print(i)

# 4128ms
