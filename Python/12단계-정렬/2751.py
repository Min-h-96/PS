# 백준 2751번 문제. 수 정렬 2
import sys

N = int(sys.stdin.readline())
lst = []
for i in range(N):
    lst.append(int(sys.stdin.readline()))
lst.sort()

for i in range(N):
    print(lst[i])

# 1568ms
