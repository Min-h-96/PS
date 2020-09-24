# 백준 15552번 문제. 빠른 A+B
import sys

T = int(sys.stdin.readline())
for i in range(0, T):
    a, b = map(int, sys.stdin.readline().split())
    print(a + b)
