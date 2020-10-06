# 백준 3009번 문제. 직사각형을 만들기 위한 마지막 점 찾기
import sys

lst_x = []
lst_y = []

for i in range(3):
    x, y = map(int, sys.stdin.readline().split())
    lst_x.append(x)
    lst_y.append(y)

for x in lst_x:
    if lst_x.count(x) == 1:
        x4 = x
    else:
        continue

for y in lst_y:
    if lst_y.count(y) == 1:
        y4 = y
    else:
        continue
print(x4, y4)

# 64ms

"""
[ x 좌표들만 들어있는 리스트 ]
[ y 좌표들만 들어있는 리스트 ]
각 리스트에서 홀수개인 걸로
마지막 점의 x 좌표 y 좌표로 지정해준다.
"""
