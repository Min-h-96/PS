# 백준 10818번 문제. 최댓값, 최소값 구하기

N = int(input())

x = map(int, input().split())
lst = list(x)
print(min(lst), max(lst))
