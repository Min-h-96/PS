# 백준 11729번 문제. 하노이탑
import sys


def hanoi(n, start, end, sup):
    if n == 1:
        print(start, end)
        return
    else:
        hanoi(n-1, start, sup, end)
        print(start, end)
        hanoi(n-1, sup, end, start)


n = int(sys.stdin.readline())

print(2**n-1)
hanoi(n, 1, 3, 2)
