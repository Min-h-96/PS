# 백준 8958번 문제. OX 퀴즈
import sys

N = int(sys.stdin.readline())

for i in range(N):
    OX = sys.stdin.readline()
    count = 1
    result = 0
    for j in range(len(OX)):
        if OX[j] == 'O':
            result += count
            count += 1
        else:
            count = 1
    print(result)

# 68ms
