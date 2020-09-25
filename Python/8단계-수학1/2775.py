# 백준 2775번 문제.
import sys

T = int(sys.stdin.readline())

for t in range(T):
    a = int(sys.stdin.readline())
    b = int(sys.stdin.readline())
    lst = [i for i in range(1, b+1)]

    for x in range(1, a+1):
        for i in range(len(lst)):
            if i == 0:
                pass
            else:
                lst[i] = lst[i] + lst[i-1]

    print(lst[b-1])

# 68ms
