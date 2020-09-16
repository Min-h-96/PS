# 백준 5622번 문제. 다이얼
import sys

D = list(sys.stdin.readline())
time = 0

for i in range(len(D)):
    if D[i] in 'ABC':
        time += 3
    elif D[i] in 'DEF':
        time += 4
    elif D[i] in 'GHI':
        time += 5
    elif D[i] in 'JKL':
        time += 6
    elif D[i] in 'MNO':
        time += 7
    elif D[i] in 'PQRS':
        time += 8
    elif D[i] in 'TUV':
        time += 9
    elif D[i] in 'WYXZ':
        time += 10
    else:
        pass

print(time)

# 64ms
