# 백준 2750번 문제. 수 정렬 1
import sys

N = int(sys.stdin.readline())
lst = []
for i in range(N):
    lst.append(int(sys.stdin.readline()))

for x in range(1, N):
    for y in range(x-1, -1, -1):
        if lst[y+1] < lst[y]:
            lst[y+1], lst[y] = lst[y], lst[y+1]
            continue
        else:
            break

for i in range(N):
    print(lst[i])

# 244ms
