# 창고 다각형_BOJ2304

import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
houses = [0 for _ in range(1001)]
lst = []
answer = 0

for _ in range(N):
    L, H = map(int, sys.stdin.readline().split())
    houses[L] = H
    lst.append(H)

lst.sort()
lst.reverse()

cur_h = 0
for h in houses:
    if (h > cur_h):
        cur_h = h
    answer += cur_h
    
    if (h != 0):
        lst.remove(h)
    
    if (len(lst) == 0):
        break
    
    if (h > lst[0]):
        cur_h = lst[0]

print(answer)