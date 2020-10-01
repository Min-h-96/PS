# 백준 4948번 문제. 베르트랑 공준
import sys


def checkPrimeNum(n):
    check = True
    if n == 1:
        check = False
    else:
        for i in range(2, int(n**0.5)+1):
            if n % i == 0:
                check = False
                return None
            else:
                continue
    if check == True:
        return n


while True:
    n = int(sys.stdin.readline())
    lst = []
    if n == 0:
        break
    else:
        for i in range(n+1, 2*n+1):
            if checkPrimeNum(i) != None:
                lst.append(checkPrimeNum(i))
        print(len(lst))

# 시간초과
