# 백준 1085번 문제. 직사각형 가장자리까지의 거리 구하기
import sys

x, y, w, h = map(int, sys.stdin.readline().split())

min = x
for i in [w-x, h-y, y]:
    if min > i:
        min = i
    else:
        continue
print(min)

# 60ms

"""
import sys

x, y, w, h = map(int, sys.stdin.readline().split())

min = x
for i in [w-x, h-y, y]:
    if x < 1 or x > w-1 or y < 1 or y > h-1:
        exit(0) # x, y에 해당하는 조건 생성
    if min > i:
        min = i
    else:
        continue
print(min)

# 64ms
"""
