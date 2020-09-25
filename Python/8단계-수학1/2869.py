# 백준 2869번 문제. 달팽이
import sys
import math

A, B, V = map(int, sys.stdin.readline().split())

d = math.ceil((V-A)/(A-B))

print(d+1)

# 68ms
# 반복문을 쓰지 않고 바로 출력해야함
