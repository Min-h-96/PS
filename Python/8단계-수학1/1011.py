# 백준 1011번 문제. 우주 순간이동
import sys

T = int(sys.stdin.readline())

for t in range(T):
    x, y = map(int, sys.stdin.readline().split())
    distance = y - x
    count = 2
    time = 0
    minus = 1

    while distance > 0:
        if count == 0:
            minus += 1
            count = 2
        count -= 1
        time += 1
        distance -= minus
    print(time)

# 1448ms

"""
import sys
r=sys.stdin.readline
n=int(r())
for _ in range(n):
	x,y=map(int,r().split());sq=int((y-x-1)**0.5)
	if y-x>sq*sq+sq:
        print(2*sq+1)
	else:
        print(2*sq)

52ms
"""
