# 백준 4153번 문제. 직각삼각형 찾기
import sys

while True:
    x, y, z = map(int, sys.stdin.readline().split())
    if (x <= 0 and y <= 0 and z <= 0) or x >= 30000 or y >= 30000 or z >= 30000:
        exit(0)
    if x**2 + y**2 == z**2 or x**2 + z**2 == y**2 or z**2 + y**2 == x**2:
        print('right')
    else:
        print('wrong')

# 60ms
