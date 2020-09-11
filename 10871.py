# 백준 10871번 문제
N, X = map(int, input().split())

a = list(map(int, input().split()))
for i in range(0, len(a)):
    if a[i] < X:
        print(a[i], end=" ")
