# 백준 10952번 문제. A+B 5번째
import sys

while True:
    a, b = map(int, sys.stdin.readline().split())
    if a == 0 and b == 0:
        break
    else:
        print(a+b)

# 68ms
