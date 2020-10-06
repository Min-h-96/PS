# 백준 2798번 문제. 블랙잭
import sys

N, M = map(int, sys.stdin.readline().split())
cards = list(map(int, sys.stdin.readline().split()))
sum_list = []

for x in range(N-2):
    for y in range(x+1, N-1):
        for z in range(y+1, N):
            sum = cards[x]+cards[y]+cards[z]
            if sum <= M:
                sum_list.append(sum)

print(max(sum_list))

# 128ms
