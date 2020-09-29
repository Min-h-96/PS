# 백준 2581번 문제. 소수의 합과 최솟값 찾기
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


M = int(sys.stdin.readline())
N = int(sys.stdin.readline())
lst = []
for i in range(M, N+1):
    if checkPrimeNum(i) != None:
        lst.append(checkPrimeNum(i))
if len(lst) == 0:
    print(-1)
else:
    print(sum(lst))
    print(min(lst))

# 76ms
