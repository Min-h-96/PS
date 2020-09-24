# 백준 1546번 문제. 성적 조작
import sys

N = int(sys.stdin.readline())

lst = list(map(int, sys.stdin.readline().split()))
maxScore = max(lst)

for i in range(len(lst)):
    lst[i] = lst[i]/maxScore*100

print(sum(lst)/len(lst))

# 60ms
