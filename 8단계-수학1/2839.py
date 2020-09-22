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

"""
n = int(input())
F = n//5
n%=5
T = 0
while F>=0:
    if n%3 == 0:
        T = n//3
        n = n%3
        break
    F-=1
    n+=5
print((n==0) and (F+T) or -1)


출처: https://doorbw.tistory.com/60 [Tigercow.Door]
"""
