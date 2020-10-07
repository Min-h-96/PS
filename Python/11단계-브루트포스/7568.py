# 백준 7568번 문제. 덩치 순위 정하기
import sys

N = int(sys.stdin.readline())
lst = []
rank_lst = [1 for i in range(N)]
for i in range(N):
    person = list(map(int, sys.stdin.readline().split()))
    lst.append(person)

for x in range(N):
    for y in range(N):
        if lst[x][0] < lst[y][0] and lst[x][1] < lst[y][1]:
            rank_lst[x] += 1
        else:
            continue

for i in rank_lst:
    print(i, end=" ")

# 64ms
